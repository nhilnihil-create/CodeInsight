#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin, x.end
#define mkp make_pair
#define trav(x, i) for(auto& i : x)
typedef long long ll;
typedef unsigned int uint;

int main(){
  string a, b;
  int n;
  cin >> n >> a >> b;
  string ans;
  for(int i = 0;i < n; i++){
    ans += a[i], ans += b[i];
  }
  cout << ans; 
  return 0;
}
