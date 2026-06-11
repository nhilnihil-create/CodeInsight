#include<bits/stdc++.h>
using namespace std;

int main(){
  string S,T;
  cin >> S;
  T=S;
  reverse(T.begin(),T.end());
  int count=0;
  for(int i=0;i<S.size();i++){
    if(S.at(i)!=T.at(i)){
      count++;
    }
  }
  cout << count/2 << endl;
}