#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1000000007;

int main(){
  int N;
  cin >> N;
  string C;
  cin >> C;
  int red = 0;
  for(int i = 0; i < N; i++){
    if(C[i] == 'R') red++;
  }
  int cnt = 0;
  for(int i = 0; i < red; i++){
    if(C[i] == 'W') cnt++;
  }
  cout << cnt << endl;
}
