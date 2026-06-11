#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  int Y=1;
  string S;
  cin>>N>>S;
  for(int X=1;X<N;X++){
    if(S.at(X)!=S.at(X-1)){
      Y++;
    }
  }
  cout<<Y<<endl;
}