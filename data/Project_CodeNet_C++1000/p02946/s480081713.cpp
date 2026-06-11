#include <bits/stdc++.h>
using namespace std;

int main(){
  int K, N;
  cin >> K >> N;
  vector<int> vec(0);
  for (int i = 0; i < K * 2 - 1; i++){
    vec.push_back(N - K + 1 + i);
  }
  sort(vec.begin(), vec.end());
  
  for (int i = 0; i < K * 2 - 1; i++){
    cout << vec[i] << " ";
    if (i + 1 == vec.size()){
      cout << endl;
    }
  }
}