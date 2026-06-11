#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=long long;

int main()
{
    int n;
    cin>>n;
    map<int,int> mp;
    for(int i=1;i<=n;i++){
        int a;
        cin>>a;
        mp[a]=i;
    }
    for(auto p:mp){
        cout<<p.second<<" ";
    }
}