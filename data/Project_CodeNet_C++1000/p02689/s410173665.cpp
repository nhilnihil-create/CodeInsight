#include <iostream>
#include <algorithm>
#include <vector>

typedef long long ll;

int main(){
  ll N, M;
  std::cin >> N >> M;
  std::vector<ll> H(N);
  std::vector<ll> A(M);
  std::vector<ll> B(M);
  for(int i = 0 ; i < N ; i++) std::cin >> H[i];
  for(int i = 0 ; i < M ; i++){
    std::cin >> A[i] >> B[i];
    A[i]--;
    B[i]--;
  }

  std::vector<bool> judge(N, true);
  for(int i = 0 ; i < M ; i++){
    if(H[ A[i] ] > H[ B[i] ]){
      judge[ B[i] ] = false;
      continue;
    }
    if(H[ A[i] ] < H[ B[i] ]){
      judge[ A[i] ] = false;
      continue;
    }
    if(H[ A[i] ] == H[ B[i] ]){
      judge[ A[i] ] = judge[ B[i] ] = false;
      continue;
    }
  }
  ll resa = std::count(judge.begin(), judge.end(), true);
  std::cout << resa << std::endl;
  return 0;
}
