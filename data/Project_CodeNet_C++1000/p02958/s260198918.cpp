#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main(void){
  int N;
  cin >> N;
  vector <int> p(N);
  rep(i,N) cin >> p[i];

  vector <int> sorted(N);
  sorted = p;
  sort(all(sorted));

  int ans = 0;  //昇順になっていないp_iの個数
  rep(i,N){
    if (p[i] != i + 1){
      ans ++;
    }
  }
  if (ans == 0 || ans == 2){
    cout << "YES" << endl;
  }else{
    cout << "NO" << endl;
  }

}
