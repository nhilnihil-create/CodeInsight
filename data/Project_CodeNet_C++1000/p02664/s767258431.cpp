#include<bits/stdc++.h>
using namespace std;
int main(){
  string S;cin>>S;
  for(int X=0;X<S.size();X++){
    if(S[X]=='?')cout<<'D';
    else cout<<S[X];
  }
}