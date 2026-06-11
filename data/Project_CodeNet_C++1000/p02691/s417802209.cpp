#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <iomanip>
# define M_PIl        3.141592653589793238462643383279502884
#define faster       ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

typedef long long ll;
typedef long double ld;

int main(){
  ll n; cin >> n;
  vector<ll> arr(n);
  map<ll,ll> m;
  for(ll i=0;i<n;i++){
    cin >> arr[i];
    if((i+arr[i])<=n){
      m[i+arr[i]]++;
    }
  }
  ll ans=0;
  for(ll i=0;i<n;i++){
    if(i-arr[i]>0){
      ans+=m[i-arr[i]];
    }
  }
  cout << ans;
}