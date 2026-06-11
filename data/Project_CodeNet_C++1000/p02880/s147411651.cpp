#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;



int main() {
  int N;
  cin >> N;//10
  bool f = false;

  for(int i = 0; i <= 9; i++){
    for(int j = 0; j <= 9; j++){
      int sum = i*j;
      if(sum == N){
       f = true;
      }
    }
  }
if(f){
  cout << "Yes" << endl;
}else{ 
  cout << "No" << endl;
}


}