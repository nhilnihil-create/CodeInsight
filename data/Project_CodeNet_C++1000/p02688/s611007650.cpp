#include<bits/stdc++.h>
using namespace std;

int main(){
  int N, K;
  cin >> N >> K;
  vector<bool> sunuke(N, false);
  for(int i = 0; i < K; i++){
    int d;
    cin >> d;
    for(int i = 0; i < d; i++){
      int a;
      cin >> a;
      sunuke.at(a-1) = true;
    }
  }
  int result = 0;
  for(bool i : sunuke){
    if(!(i)){
      result ++;
    }
  }
  cout << result << endl;
}