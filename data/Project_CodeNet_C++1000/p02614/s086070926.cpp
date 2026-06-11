#include <iostream>
#include <bits/stdc++.h>
#include <stdio.h>

typedef long long ll;
using namespace std;



bool isPrime(int n){
    if(n < 2){
        return 0;
    }
    if(n%2 == 0){
        return n==2;
    }
    for(int i=3;i*i<=n;i++){
        if(n%i == 0) return 0;
    }
    return 1;
}

void allPoss(int indx,int n,vector<int> v,vector<vector<int>> &vv){
    if(indx == n) {
        vv.push_back(v);
        return;
    }
    v.push_back(indx);
    allPoss(indx+1,n,v,vv);
    v.pop_back();
    allPoss(indx+1,n,v,vv);
}

int main() {
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<char>> g(n,vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)cin>>g[i][j];
    }
    vector<vector<int>> vn;
    vector<vector<int>> vm;
    vector<int> v;
    allPoss(0,n,v,vn);
    v.clear();
    allPoss(0,m,v,vm);
    int f = 0;
    for(int i=0;i<vn.size();i++){
        for(int j=0;j<vm.size();j++){
            vector<vector<char>> gg(n,vector<char>(m));
            for(int ii=0;ii<n;ii++){
                for(int ji=0;ji<m;ji++)gg[ii][ji]=g[ii][ji];
            }
            for(int r=0;r<vn[i].size();r++){
                for(int h=0;h<m;h++)gg[vn[i][r]][h] = '.';

            }
            for(int c=0;c<vm[j].size();c++){
                for(int h=0;h<n;h++)gg[h][vm[j][c]] = '.';

            }
            int l =0;
            for(int ii=0;ii<n;ii++){
                for(int ji=0;ji<m;ji++){
                    if(gg[ii][ji] == '#') l++;
                }
            }
            if(l == k)f++;
        }
    }
    cout<<f<<endl;
    return 0;
}
