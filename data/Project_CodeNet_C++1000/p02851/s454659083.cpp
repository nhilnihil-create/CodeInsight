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

  ll n,k;
  cin >> n >> k;
  ll a[n];
  ll s[n+1];

  rep(i,n){
    cin >> a[i];
  }
  s[0]=0;
  rep(i,n){
    s[i+1] = s[i] + a[i];
    s[i+1] %=k;
  }
  ll ans=0;
  //  multiset<ll> cou;
  map<ll, ll> cou;
    rep(i,n+1){
    s[i] -= (i%k);
    s[i] = (s[i]+k)%k;
    if(i-k>=0){
      --cou[s[i-k]];
    }
    ans += cou[s[i]];
    cou[s[i]]++;
    //    cout << "sum ans " << s[i] << " " << ans << endl;    
  }
  
  cout << ans << endl;
  
  
  return 0;
    

}
