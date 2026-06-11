#include <bits/stdc++.h>
using namespace std; 

int main(){
  long long N;
  cin >> N;
  string S="";
  while(N){
    N--;
    char C='a'+N%26;
    S.push_back(C);
    N/=26;
  }
  reverse(S.begin(),S.end());
  cout << S << endl;
}