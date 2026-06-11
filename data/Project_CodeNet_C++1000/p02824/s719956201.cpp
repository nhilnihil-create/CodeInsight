#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = (n)-1; i >= 0; i--)
#define rep1(i,n) for(int i = 1; i <= (n); i++)
#define rrep1(i,n) for(int i = (n); i > 0; i--)

#define ll long long
#define pi pair<int, int>
#define pll pair<ll, ll>

#define MOD 1000000007
#define INF 1000000000000000LL

using namespace std;

int main(){
  ll n,m,v,p;cin>>n>>m>>v>>p;
  vector<ll> a(n);
  rep(i, n)cin>>a[i];
  sort( a.rbegin(), a.rend() );

  int max=n, min=-1, mid;
  while(max-min>1){
    mid = (max+min)/2;
    if(a[mid]+m<a[p-1]){
      max=mid;
      continue;
    }

    ll used = m*(p-1+1);
    used += (n-1-mid)*m;
    for(int i=p-1; i<mid; i++) used+=a[mid]+m-a[i];

//cout<<mid<<' '<<used<<endl;

    if(used>=v*m)min=mid;
    else max=mid;
  }

  cout<<min+1;

  return 0;
}