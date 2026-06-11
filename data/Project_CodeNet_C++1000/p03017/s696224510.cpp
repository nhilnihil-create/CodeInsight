#include <bits/stdc++.h>
using namespace std;
int main(){
  int N,A,B,C,D;cin>>N>>A>>B>>C>>D;
  A--;B--;C--;D--;
  string S;cin>>S;
  if(C==D){puts("No");return 0;}
  if(C<D){
    for(int i=A;i<D;i++){
      if(S.at(i)==S.at(i+1)&&S.at(i)=='#'){puts("No");return 0;}
    }
    puts("Yes");return 0;
  }
  for(int i=A;i<C;i++){
    if(S.at(i)==S.at(i+1)&&S.at(i)=='#'){puts("No");return 0;}
  }
  for(int i=B-1;i<D;i++){
    if(S.at(i)==S.at(i+1)&&S.at(i)==S.at(i+2)&&S.at(i)=='.'){puts("Yes");return 0;}
  }
  puts("No");
}