#include<bits/stdc++.h>
using namespace std;
int main(){
  string S;
  cin>>S;
  string T=S.substr(0,(S.size()-1)/2),U=S.substr((S.size()+3)/2-1);
  for(int i=0;i<S.size()/2;i++)
    if(S[i]!=S[S.size()-1-i]){
      puts("No");
      return 0;
    }
  for(int i=0;i<T.size()/2;i++)
    if(T[i]!=T[T.size()-1-i]){
      puts("No");
      return 0;
    }
  for(int i=0;i<U.size()/2;i++)
    if(U[i]!=U[U.size()-1-i]){
      puts("No");
      return 0;
    }
  puts("Yes");
}