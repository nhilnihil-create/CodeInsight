#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 10000000000 + 7;

int main(){
  cout << setprecision(10);
  int N,x,y;
  cin >> N >> x >> y;
  x--; y--;

  vector<int> ans(N,0);
  for(int i = 0; i < N-1; i++){
    for(int j = i+1; j < N; j++){
      int len = j - i;

      len = min(len, abs(i - x) + 1 + abs(j - y));
      ans[len]++;
    }
  }

  for(int i = 1; i < N; i++){
    cout << ans[i] << endl;
  }
}
