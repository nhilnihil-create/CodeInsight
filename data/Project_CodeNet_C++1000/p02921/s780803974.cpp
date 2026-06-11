#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string S,T;
  cin>>S>>T;
  int U=0;
  for(int X=0;X<3;X++){
    if(S[X]==T[X]){
      U++;
    }
  }
  cout<<U<<endl;
}