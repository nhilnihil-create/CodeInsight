/*
  The Island Was Silent before.
  .....
  And One day again it became Silent.
*/
#include<bits/stdc++.h>
using namespace std;
 
#define endl '\n'
#define ll  long long
#define modd(a,b) ((a+2*b)%b)
#define debug(a) cout << #a << ": " << (a) << "\n"
#define ioso ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define rtt cerr << "Time: " << clock()*1.0 / CLOCKS_PER_SEC << endl;
#define ffe freopen("input.txt","r",stdin), freopen("output.txt","w",stdout);
 
int main() {
  ioso
  #ifndef ONLINE_JUDGE
  ffe
  #endif
  ll n, k; cin >> n >> k;
  int a[200010];
  int fr[200010];
  memset(fr,0,sizeof(fr));
  for(int i=1;i<=n;i++) {
    cin >> a[i];
  }
  int as=1;
  std::vector<ll> vs;
  vs.push_back(-12);
  for(int i=1;i<=n;i++) {
    if(fr[as]==0) {
      fr[as]=i;
      vs.push_back(as);
      as = a[as];

    }
    else {
      break;
    }
  }

  ll siz = vs.size();
 // cout << siz << endl;
 
  siz-=1;
  if(k<=siz) {
    cout << a[vs[k]] << endl;
    return 0;
  }

  ll numas = (siz-fr[as])+1;
//  debug(as);
//  debug(numas);
  k-= (siz-numas);
//  debug(k);
  //ll oti = siz-numas;
  ll ff = k%numas;
  if(ff==0) {ff=numas;}
 // debug(ff);
  ll ans = a[vs[ff+(siz-numas)]];
 // debug(vs[ff+(siz-numas)]);
 // cout << ff-fr[as]+1 << endl;
  cout << ans << endl;
  
  //cout << ans << endl;
}