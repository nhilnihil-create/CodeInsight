#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;

int main() {
  
  int H, N;
  cin >> H >> N;
  
  int A = 0;
  rep(i,N){
    int buf;
    cin >> buf;
    A += buf;
  }
  if(H <= A){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}
