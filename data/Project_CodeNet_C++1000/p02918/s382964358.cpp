#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, k; cin >> n >> k;
  string s; cin >> s;
  int len = 1; // 反転した数だけ不幸せな人がいる
  for(int i=1; i<n; i++){
    if(s[i] != s[i-1]) len++;
  }

  int unhapp = max(len - 2*k, 1); // 1度の反転でmax2人幸せになれる
  cout << n - unhapp << endl;
}
