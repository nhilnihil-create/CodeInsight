#include <bits/stdc++.h>
using namespace std;

int main() {
  
  
  int n, k;
  cin >> n >> k;
  //n = スヌケくんの数 k = お菓子の種類
  //d = その種類のお菓子を持っている人数
  
  vector<int> vec(n);
  
  for(int i = 0; i < n; i++){
    vec.at(i) = 0;
  }
  
  for(int i = 0; i < k; i++){
    int d;
    cin >> d;
    for(int j = 0; j < d; j++){
      int a;
      cin >> a;
      int b = a - 1;
      vec.at(b) = vec.at(b) + 1;
    }
  }
  
  int total = 0;
  
  for(int i = 0; i < n; i++){
    if(vec.at(i) == 0){
      total = total + 1;
    }
  }
  
  cout << total << endl;

  
  
}

