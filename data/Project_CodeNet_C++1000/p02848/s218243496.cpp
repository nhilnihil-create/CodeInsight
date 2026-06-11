#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  string S;
  cin>>N>>S;
  for(int X=0;X<S.size();X++){
    if(((int)S[X])+N>(int)'Z'){
      S[X]=(char)((int)S[X]+N-26);
    }
    else{
      S[X]=(char)((int)S[X]+N);
    }
  }
  cout<<S<<endl;
}