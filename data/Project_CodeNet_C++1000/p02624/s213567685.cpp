#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0;i < (int)(n);i++)

int main(){
  ll n;
  cin >> n;
  ll ans = 0;
  rep(i,n){
    ans += ll(i+1)*(n/ll(i+1))*(1 + (n/ll(i+1)))/2;  
  }
  cout << ans << endl;

}
