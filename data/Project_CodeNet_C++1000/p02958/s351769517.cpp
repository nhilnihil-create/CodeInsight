#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, n) for (int i = 1; i <= (int)(n); i++)

int main(){
  int N;
  cin >> N;

  int num;
  int cnt = 0;
  for (int i = 1; i <= N; i++){
    cin >> num;
    if (num != i) cnt += 1;
  }

  cout << (cnt <= 2 ? "YES" : "NO") << endl;
}