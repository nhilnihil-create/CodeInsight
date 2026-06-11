#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main(){
  int N, K;
  cin >> N >> K ;
  vector<int> v(N, 0);
  int d=0;
  for (int i = 0; i < K; i++) {
    cin >> d;
    for (int j = 0; j < d; j++) {
        int indx=0;
        cin >> indx;
        v.at(indx-1) += 1;
    }
    
  }
  //cout the 0
  size_t n_count = std::count(v.begin(), v.end(), 0);
  std::cout << n_count << std::endl;
  
}