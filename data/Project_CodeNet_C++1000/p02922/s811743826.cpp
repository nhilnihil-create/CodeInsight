#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < int(n);i++)
const ll mod = 1e9+7;


int main(){
  int a,b;
  cin >> a >> b;
  int now = 1;
  int ans = 0;
  while(now < b){
    now += a - 1;
    ans++;
  }
  cout << ans << endl;


  return 0;
}