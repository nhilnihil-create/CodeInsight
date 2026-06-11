#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main(void){
  string s;
  cin >> s;

  string week[7] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
  rep(i,7){
    if (s == week[i]){
      cout << 7 - i << endl;
    }
  }
}
