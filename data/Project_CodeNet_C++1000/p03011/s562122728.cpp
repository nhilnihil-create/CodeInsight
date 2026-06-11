#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, n) for (int i = 1; i <= (int)(n); i++)

int main(){
  int A, B, C;
  cin >> A >> B >> C;
  vector<int> vec;
  vec.push_back(A);
  vec.push_back(B);
  vec.push_back(C);
  int min = 100000;
  for (int i = 0; i < vec.size(); i++){
    for (int j = i + 1; j < vec.size(); j++){
     if (min > vec.at(i) + vec.at(j)){
       min = vec.at(i) + vec.at(j);
     } 
    }
  }
  cout << min << endl;
}