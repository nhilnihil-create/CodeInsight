#include <iostream>
#include <vector>
using namespace std;

int main(){
  int N, M, K;
  cin >> N >> M >> K;
  vector<int> A(N), B(M);
  long long sumb = 0;
  for(int i=0; i<N; i++){
    cin >> A.at(i);
  }
  for(int i=0; i<M; i++){
    cin >> B.at(i);
    sumb += B.at(i);
  }
  int ans = 0;
  long long time = 0;
  int index = M-1;
  for(int i=0; i<=N; i++){
    int num = i;
    if(i>0) time += A.at(i-1);
    if(time>K) break;
    while(time+sumb>K){
      sumb -= B.at(index);
      index--;
    }
    ans = max(ans,i+index+1);
  }
  cout << ans;
  return 0;
}