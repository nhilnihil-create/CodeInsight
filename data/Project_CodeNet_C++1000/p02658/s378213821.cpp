#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;cin>>N;
  long long H=1;bool F=false;bool J=false;long long P=0;long long U=1;
  for(int X=0;X<N;X++){
    long long A;cin>>A;
    string S=to_string(A);P+=S.size()-1;
    if(A==0)J=true;
    H*=A;U*=A;
    if(H/1000000000000000001!=0)F=true;
    H%=1000000000000000001;
  }
  if(J)cout<<0<<endl;
  else if(U==1000000000000000000)cout<<1000000000000000000<<endl;
  else if(F||P>=18)cout<<-1<<endl;
  else cout<<H<<endl;
}