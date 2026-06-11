#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  int N;
  cin >> N;
  for(int i=0;i<N*0.001+1;i++){
    if(i*1000-N>-1 && i*1000-N<1000){
      cout << i*1000-N << endl;
    }
  }
}