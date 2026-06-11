#include <bits/stdc++.h>
using namespace std;

int main() {
  int a;
  int K;
  cin >> a;
  vector<int> v(a+1);
  int tmp;
  for (int i = 0; i < a-1; i++){
    cin >> tmp;
    K=v.at(tmp)+1;
    v.at(tmp)=K; 
  }
   for (int i = 1; i < a+1; i++){
    cout << v.at(i) << endl;
   }
}
