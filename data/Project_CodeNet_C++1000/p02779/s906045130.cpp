#include <bits/stdc++.h>
using namespace std;

int main(void){
  
  int N,A;
  map<int,int> mp{};
  cin >> N;
  
  for(int i=0;i<N;i++){
      cin >> A;
      mp[A] = 1;
  }
  
  if(mp.size() == N){
      cout << "YES" << endl;
  }
  else{
      cout << "NO" << endl;
  }
}