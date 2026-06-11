#include<bits/stdc++.h>
typedef long long ll;
#define F(i,L,R) for (ll i = L; i < R; i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define re(x) scanf("%lld",&x)
using namespace std;


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n;
  cin>>n;
  ll a[n];
  F(i,0,n) cin>>a[i];

  ll cnt = 0;
  F(i,0,n) if((i+1)%2==1 && a[i]%2==1) cnt++;

  cout<<cnt<<endl;
  return 0;
}
