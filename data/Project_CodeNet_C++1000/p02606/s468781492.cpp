#include "bits/stdc++.h"
using namespace std;
#define dbg(var) cout<<#var<<"="<<var<<" "
#define nl cout<<"\n"
#define fr(i,n) for(int i=0;i<n;i++)
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define fast ios::sync_with_stdio(false);cin.tie(0);
#define vi vector<int>
#define vvi vector<vi>
#define pb push_back
#define fa(v) for(auto &i:v)
#define all(v) v.begin(),v.end()
#define sz(v) (int)(v.size())
#define int long long
int32_t main()
{
  int a,b,c; cin >> a >> b >> c;
  cout << (b/c - --a/c);  		
}