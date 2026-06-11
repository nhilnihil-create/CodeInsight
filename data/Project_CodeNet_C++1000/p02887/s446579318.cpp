#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=long long;

int main()
{
    int n,ans;
    string s;
    cin>>n>>s;
    ans=n;
    rep(i,n-1) ans-=s[i]==s[i+1];
    cout<<ans;
}