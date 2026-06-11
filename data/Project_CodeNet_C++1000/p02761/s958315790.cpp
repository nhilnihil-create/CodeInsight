#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N,M;
  cin>>N>>M;
  bool F=true;
  string D="aaa";
  for(int X=0;X<M;X++){
    int S,C;
    cin>>S>>C;
    if((D[S-1]!='a'&&(int)(D[S-1]-'0')!=C)||(N!=1&&S==1&&C==0)){
      F=false;
    }
    else{
      D[S-1]=(char)C+'0';
    }
  }
  if(F==false){
    cout<<-1<<endl;
  }
  else{
    for(int X=0;X<N;X++){
      if(D[X]=='a'){
        if(X==0&&N!=1){
          cout<<1;
        }
        else{
          cout<<0;
        }
      }
      else{
        cout<<D[X];
      }
    }
    cout<<endl;
  }
}