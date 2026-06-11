#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  ll n; int p;
  string s;
  cin >> n >> p;
  cin >> s;
   ll ans = 0;
  if(p==2 || p==5){
     reverse(s.begin(),s.end());
     for(ll i = 0; i < n; i++){
         if((s[i]-'0')%p ==0) ans += n-i;
    }
  cout << ans <<endl;
  return 0;
  }
   reverse(s.begin(), s.end());
   ll ten = 1;
   ll d[n+5]={0};
   for(ll i=0;i<n;i++){
    ll a = (s[i]-'0')*ten%p;
    ten = ten*10%p;
    d[i+1] = (d[i]+ a)%p;
    }
    ll cnt[p+1]={0};
    for(ll i =0; i<=n;i ++){
       cnt[d[i]]++;
   }
   for(ll i=0; i<p;i ++){
        ll k = cnt[i];
        ans += k*(k-1)/2;
   }
   cout << ans<< endl;
}
       