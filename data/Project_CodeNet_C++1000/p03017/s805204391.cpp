#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define MOD 1000000007
#define INF 1000000000000000000

int main(){
  int N,A,B,C,D;
  string S;
  cin>>N>>A>>B>>C>>D>>S;
  A--,B--,C--,D--;
  if(C<B){
    bool flag=true;
    for(int i=A+1;i<C-1;i++){
      if(S.at(i)=='#'&&S.at(i+1)=='#'){
        flag=false;
        break;
      }
    }
    for(int i=B+1;i<D-1;i++){
      if(S.at(i)=='#'&&S.at(i+1)=='#'){
        flag=false;
        break;
      }
    }
    if(flag){
      cout<<"Yes"<<endl;
    }else{
      cout<<"No"<<endl;
    }
  }else if(D<C){
    bool flag=true;
    for(int i=A+1;i<C-1;i++){
      if(S.at(i)=='#'&&S.at(i+1)=='#'){
        flag=false;
        break;
      }
    }
    bool sub=false;
    for(int i=B;i<=D;i++){
      if(S.at(i-1)=='.'&&S.at(i)=='.'&&S.at(i+1)=='.'){
        sub=true;
        break;
      }
    }
    if(flag&&sub){
      cout<<"Yes"<<endl;
    }else{
      cout<<"No"<<endl;
    }
  }else{
    bool flag=true;
    for(int i=A+1;i<D-1;i++){
      if(S.at(i)=='#'&&S.at(i+1)=='#'){
        flag=false;
        break;
      }
    }
    if(flag){
      cout<<"Yes"<<endl;
    }else{
      cout<<"No"<<endl;
    }
  }
}
