#include <bits/stdc++.h>
using namespace std;
int main(){
  int N, tmp;
  cin >> N;
  int shine[200001] = {0};
  for(int i = 1; i < N; i++){
    cin >> tmp;
    shine[tmp]++;
  }
  
  for(int i = 1; i <= N; i++){
    cout << shine[i] << endl;    
  }
}
    