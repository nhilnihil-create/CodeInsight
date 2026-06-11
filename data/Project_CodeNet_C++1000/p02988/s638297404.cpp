#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0;i < (int)(n);i++)

int main(){
  int n;
  cin >> n;
  int cnt = 0;
  vector<int> v(n);
  rep(i,n) cin >> v[i];
  for (int i = 1;i < n-1;i++){
    if (min({v[i-1],v[i],v[i+1]}) != v[i] && max({v[i-1],v[i],v[i+1]}) != v[i]) cnt++;
  }
  cout << cnt << endl;

  return 0;
  
}
