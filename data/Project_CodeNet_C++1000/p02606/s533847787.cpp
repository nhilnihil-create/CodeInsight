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
  ll l,r,d;
  cin>>l>>r>>d;

  ll p = l/d;
  if(l%d!=0) p++;
  ll cnt = 0;
  while(p*d<=r) {
      cnt++;
      p++;
  }

  cout<<cnt<<endl;


  return 0;
}
