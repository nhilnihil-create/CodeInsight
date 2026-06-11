#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int n;
  ll k;
  cin >> n >> k;
  vector<int> ai(n), fi(n);
  for(int i=0; i<n; ++i) cin >> ai[i];
  for(int i=0; i<n; ++i) cin >> fi[i];
  sort(ai.begin(),ai.end());
  sort(fi.begin(),fi.end());
  reverse(fi.begin(),fi.end());
  /*
  for(int i=0; i<n; ++i) cout << ai[i] << " ";
  cout << endl;
  for(int i=0; i<n; ++i) cout << fi[i] << " ";
  cout << endl;
  */
  ll l=-1, r= (ll)ai[n-1]*(ll)fi[0];
  while(l<r-1){
    ll mid = (l+r)/2;
    ll cnt = 0;
    for(int i=0; i<n; ++i){
      ll tar = mid/(ll)fi[i];
      if(tar < ai[i]) cnt += (ll)ai[i] - tar;
    }
    //cout << l << " " << r << " " << mid << " " << cnt << endl;
    if(cnt > k) l = mid;
    else r = mid;
  }
  cout << r << endl;
}