#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll k,q;
  cin >> k >> q;

  vector<ll> d(k);
  rep(i,k) cin >> d[i];

  rep(i,q){
    ll n,x,m;
    cin >> n >> x >> m;
    x%=m;
    vector<ll> td(k);
    ll zcnt=0;
    ll sum=0;
    rep(j,k){
      td[j] = d[j]%m;
      if(td[j]==0)zcnt++;
      sum += td[j];
    }
    ll loop = (n-1)/k;
    ll fin = x + loop*sum;
    //    cout << "loop sum/loop " << loop << " " << sum << endl;

    ll ans = n-1;
    ans -= (fin/m);
    ans -= zcnt*loop;
    //    cout << zcnt << endl;
    //    cout << "after loop " << (fin/m - x/m) << endl;
    //    cout << "after loop " << ans << endl;
    ll pre = fin%m;
    ll c = fin%m;
    //    cout << "fin " << fin << endl;
    //    cout << "pre ans " << ans << endl;
    for(int i= loop*k+1; i<n;i++){
      //      cout << ans << endl;
      c+=d[(i-1)%k];
      c%=m;
      if(pre>=c) ans--;
      pre = c;
    }
    //    cout << "an " <<  c << endl;
    cout << ans << endl;
  }
  


  
  //  cout << endl << endl;
  //  cout << static_cast<double>(clock()) / CLOCKS_PER_SEC << "s"<<endl;
  return 0;
    

}
