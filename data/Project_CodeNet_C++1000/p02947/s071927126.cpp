#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=long long;

int main()
{
    int n;
    ll ans=0;
    cin>>n;
    map<string,int> mp;
    rep(i,n){
        string s;
        cin>>s;
        sort(s.begin(),s.end());
        mp[s]++;
        ans+=mp[s]-1;
    }
    cout<<ans;
}