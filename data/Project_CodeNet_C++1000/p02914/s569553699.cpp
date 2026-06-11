#include <iostream>
#include <utility>
#include <vector>
#include <set>
#include <algorithm>

using lli=long long int;

int main(){
  int N;
  std::cin >> N;

  std::vector<lli> A_arr(N), B_arr(N);
  for(int i = 0; i < N; i++) std::cin >> A_arr[i];

  lli xor_total = 0;
  for(int i = 0; i < N; i++) xor_total ^= A_arr[i];
  for(int i = 0; i < N; i++) B_arr[i] = A_arr[i] & (~xor_total);

  int nt = 0;
  for(int nd = 60; nd >= 0; nd--){
    lli ndi = 1LL<<nd;
    int i = nt;
    for(; i < N; i++) if(B_arr[i]&ndi) break;
    if(i == N) continue;
    std::swap(B_arr[nt], B_arr[i]);
    for(i = 0; i < N; i++){
      if(i == nt) continue;
      if(B_arr[i] & ndi) B_arr[i] ^= B_arr[nt];
    }
    nt++;
  }
  lli xor_partial = 0;
  for(int i = 0; i < N; i++) xor_partial ^= B_arr[i];

  std::cout << 2*xor_partial+xor_total << std::endl;

  return 0;
}

