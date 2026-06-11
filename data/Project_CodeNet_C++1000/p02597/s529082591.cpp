#include <bits/stdc++.h>
using namespace std; 

int main(){
  int N;
  string S,T;
  cin >> N >> S;
  T=S;
  sort(S.begin(),S.end());
  int count=0;
  for(int i=0;i<N;i++){
    if(S.at(i)!=T.at(i)){
      count++;
    }
  }
  cout << count/2 << endl;
}