#include<bits/stdc++.h>
using namespace std;
int main(){
    const int mod=1000000007;
    int n,k;
    cin>>n>>k;
    int a[n-1],b[n-1];
    vector<vector<int>>pas(n);
    for(int i=0;i<n-1;i++){
        cin>>a[i]>>b[i];
        pas[a[i]-1].push_back(b[i]-1);
        pas[b[i]-1].push_back(a[i]-1);
    }
    long long x=k;
    k--;
    queue<int>q;
    int check[n]={};
    check[0]=1;
    for(int i=0;i<pas[0].size();i++){
        q.push(pas[0][i]);
        check[pas[0][i]]=1;
        x*=(k-i);
        if(x<=0){
            cout<<"0"<<endl;
            return 0;
        }
        x%=mod;
    }
    k--;
    while(q.size()){
        int f=q.front();
        q.pop();
        for(int i=0;i<pas[f].size();i++){
            if(check[pas[f][i]]==0){
                check[pas[f][i]]=1;
                q.push(pas[f][i]);
            }
        }
        for(int i=0;i<pas[f].size()-1;i++){
            x*=(k-i);
            if(x<0){
                cout<<"0"<<endl;
                return 0;
            }
            x%=mod;
        }
    }
    cout<<x<<endl;
    return 0;
}