#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 1000000000 + 7;

int main(){
  cout << setprecision(10);
  int N,K;
  cin >> N >> K;

  if(K > (N-1)*(N-2)/2){
    cout << -1 << endl;
    return 0;
  }


  // 追加するへんの数
  int M = 0;
  M = N-1 + (N-1)*(N-2)/2 - K;
  cout << M << endl;

  // 0と、1からN-1までをつないでおく
  for(int i = 2; i <= N; i++){
    cout << 1 << " " << i << endl;
  }
  // iとj(1<=i<j<=N)の組みを、(N-1)*(N-2)/2 - K本出す
  int target = (N-1)*(N-2)/2 - K;
  int num = 0;
  cerr << "target: " << target << endl;
  for(int i = 2; i <= N-1; i++){
    for(int j = i+1; j <= N; j++){
      if(num == target) break;
      cout << i << " " << j << endl;
      num++;
    }
  }
}
