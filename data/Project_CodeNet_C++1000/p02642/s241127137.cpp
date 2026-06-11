#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
typedef long long ll;

int main(){
  ll N;
  cin >> N;
  ll a[N];
  for(ll i=0;i<N;i++){
    cin >> a[i];
  }
  sort(a,a+N);
  bool s[a[N-1]+1];
  for(ll i=1;i<a[N-1]+1;i++){
    s[i] = true;
  }
  ll ans = 0;
  for(ll i=0;i<N;i++){
    if(i < N-1 && a[i]==a[i+1]){
      s[a[i]] = false;
    }
    if(s[a[i]]) ans++; 
    ll j=1;
    while(a[i]*j<=a[N-1]){
      s[a[i]*j] = false;
      j++;
    }
  }
  cout << ans << endl;
}
