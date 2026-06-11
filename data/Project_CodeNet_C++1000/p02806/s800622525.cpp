#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define pb push_back
#define pii pair<ll,ll>
#define pi pair<int ,int> 
#define REP(i,a,n) for(int i=a;i<n;i++)
#define rep(i,a,n) for(int i=a;i>=n;i-- )
#define F first
#define S second
int main() {
     map<string,ll>mp;
     int n;
     cin>>n;ll ans=0;
     REP(i,0,n)
     {
         string s;int t;
         cin>>s;cin>>t;
         ans+=t;
         mp[s]=ans;
     }
     string x;
     cin>>x;
    ll te=mp[x];
    cout<<ans-te;

   
   
	return 0;
}