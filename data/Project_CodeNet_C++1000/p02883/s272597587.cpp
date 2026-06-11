#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  ll n, k;
  cin >> n >> k;
  vector<ll> Ai(n);
  vector<ll> Fi(n);
  for(int i=0; i<n; ++i) cin >> Ai.at(i);
  for(int i=0; i<n; ++i) cin >> Fi.at(i);
  sort(Ai.begin(),Ai.end());
  reverse(Ai.begin(),Ai.end());
  sort(Fi.begin(),Fi.end());
  /*
  for(int i=0; i<n; ++i){
    cout << Ai.at(i) << " ";
  }
  cout << endl;
  for(int i=0; i<n; ++i){
    cout << Fi.at(i) << " ";
  }
  cout << endl;
  */
  ll l=-1, r=Ai.at(0)*Fi.at(Fi.size()-1)+1;
  while(l<r-1){
    ll mid= (l+r)/2;
    ll count=0;
    for(int i=0; i<n; ++i){
      if(Ai.at(i)*Fi.at(i) < mid) continue;
      else count += Ai.at(i) - mid/Fi.at(i);
    }
    //cout << l << " " << r << " " << mid << " " << count << endl;
    if(count <=k) r=mid;
    else l=mid;
  }
  cout << r << endl;
}