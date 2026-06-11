#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define pb push_back
#define pii pair<ll,ll>
#define pi pair<int ,int> 
#define REP(i,a,n) for(int i=a;i<n;i++)
#define rep(i,a,n) for(int i=a;i>=n;i-- )
int main() {

 ll m;
 cin>>m;
 ll ans=0,pro=0;
 REP(i,0,m)
 {
     ll d,c;
     cin>>d>>c;
     pro+=d*c;
     ans+=c;
 }
 ans--;
 ans+=(pro-1)/9;
 cout<<ans;
	return 0;
}