#include<bits/stdc++.h>
using namespace std;
int main(){
string S;
  int64_t K;
  cin>>S>>K;
  int64_t sum=1;
  int64_t ans=0;
  int64_t N=S.size();
  bool x=true;
  for(int i=1;i<N;i++)
    if(S.at(i)!=S.at(0)){x=false; break;}
  if(x)cout<<(N*K)/2<<endl;
  else{
  S+='?';
  for(int i=1;i<=N;i++){
    if(S.at(i)==S.at(i-1))
      sum++;
    else{
    ans+=sum/2; sum=1;
    }
  }ans*=K;
  if(S.at(0)==S.at(N-1)){
  int a,b; a=1; b=1;
    for(int i=1;i<N;i++){
    if(S.at(i)==S.at(i-1))
      a++;
      else
        break;
    }for(int i=N-1;1<=i;i--){
    if(S.at(i)==S.at(i-1))
      b++;
      else
        break;
    } if(a%2==1 && b%2==1)
      ans+=(K-1);
  
  }cout<<ans<<endl;
  }
   return 0;
}
