#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

long long MOD = 1e9+7;
int MAX_INT = 1e9;

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N;
  cin >> N;
  vector<string> s(N);
  vector<int> t(N);
  for(int i = 0; i < N; i++) {
    cin >> s[i] >> t[i];
  }
  string X;
  cin >> X;

  int cnt = 0;
  bool judge = false;
  for(int i = 0; i < N; i++) {
    if(judge) {
      cnt += t[i];
    }
    if(s[i] == X) {
      judge = true;
    }
  }

  cout << cnt << endl;

    return 0;
}
