#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6+5;
int prime[MAXN]={0};
vector<int>fac[MAXN];
void getprime(){
    for(int i=2;i<MAXN;i++){
        if(!prime[i]){
            //fac[i].push_back(i);
            for(int j=i*2;j<MAXN;j+=i)
            {
                prime[j]=1;
                fac[j].push_back(i);
            }
        }
    }
    for(int i=2;i<MAXN;i++){
        if(!prime[i])
            fac[i].push_back(i);
    }

}
int a[MAXN]={0};
map<int,int>mm;
int solve(int n){
    if(mm[n]>1)
        return 0;
    vector<int>vv;
    vv.push_back(1);
    for(auto pr:fac[n]){
        vector<int>cc;
        int p1=pr;
        while(n%p1==0){
            cc.push_back(p1);
            p1*=pr;
        }
        int sz = vv.size();
        for(int i=0;i<sz;i++){
            for(auto p:cc){
                vv.push_back(vv[i]*p);
            }
        }
    }
    for(auto ele:vv){
        //cout <<ele <<" ";
        if(ele!=n&&mm[ele]){
            return 0;
        }
    }
    return 1;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    getprime();
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
        mm[a[i]]++;
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        ans+=solve(a[i]);
    }
    cout <<ans << endl;
    return 0;
}
