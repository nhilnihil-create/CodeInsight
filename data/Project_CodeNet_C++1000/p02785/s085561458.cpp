#include <bits/stdc++.h>
using namespace std;

int main(void){
  
  int N,K;
  unsigned long long count = 0;
  cin >> N >> K;
  int data[N];
  for(int i=0;i<N;i++) cin >> data[i];
  sort(data,data+N,greater<int>());
  
  for(int i=0;i<N;i++){
      if(K > 0){
          K--;
      }
      else{
          count += data[i];
      }
  }
  cout << count << endl;
}