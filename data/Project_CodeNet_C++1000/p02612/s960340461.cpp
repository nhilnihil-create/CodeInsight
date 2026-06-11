#include<iostream>
#include<cmath>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
typedef long long ll;

int main(){
  ll N; cin >> N;
  ll ans = N % 1000;
  if(ans) ans = 1000 - ans;

  cout << ans << endl;
}
