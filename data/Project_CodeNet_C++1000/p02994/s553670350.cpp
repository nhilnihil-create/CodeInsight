#include<bits/stdc++.h>
using namespace std;
int main(){
  int N,L;
  cin>>N>>L;
  int S=L+N-1;
  int eat;
  if(S<=0){
    eat=S;
  }
  else if(L>=0){
    eat=L;
  }
  else{
    eat=0;
  }
  int ans=(S+L)*(S-L+1)/2-eat;
  cout<<ans<<endl;
}
  