#include<bits/stdc++.h>
using namespace std;
int main(){
  int N,A,B,C,D;
  string S;
  cin>>N>>A>>B>>C>>D>>S;
  for(int i=A-1;i<C;i++){
    if(S[i]=='#' && S[i+1]=='#'){
      puts("No");
      return 0;
    }
  }
  for(int i=B-1;i<D;i++){
    if(S[i]=='#' && S[i+1]=='#'){
      puts("No");
      return 0;
    }
  }
  if(C<D){
    puts("Yes");
    return 0;
  }
  for(int i=B-2;i<D-1;i++)
    if(S[i]=='.' && S[i+1]=='.' && S[i+2]=='.'){
      puts("Yes");
      return 0;
    }
  puts("No");
}