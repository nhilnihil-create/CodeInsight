#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#define rep(i, n) for(int i=0; i<n; i++)

using namespace std;

int main(){
  int N, K, S;
  cin >> N >> K >> S;
  //入力終了

  //K個Sを並べた後，適当な数をN-K個並べればよい
  int ans[N];
  rep(i, K)
    ans[i] = S;
  
  //S=10^9のとき，S+1をans[]に入れると問題の条件を満たさないことに注意
  int insert;
  if(S == 1000000000)
    insert = 1;
  else
    insert = S+1;
  for(int i=K; i<N; i++)
    ans[i] = insert;

  //解答
  rep(i, N)
    cout << ans[i] << " ";
  cout << endl;
  
  return 0;
}
