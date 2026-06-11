#include<bits/stdc++.h>
using namespace std;
int main(){
  int64_t N,P;cin>>N>>P;
  string s;cin>>s;
  if(P==2){
  int64_t ans=0;
    for(int64_t i=N-1;0<=i;i--){
    int64_t b=s.at(i)-'0';
      if(b%2==0)ans+=i+1;
    }
    cout<<ans<<endl;
  }else if(P==5){
  int64_t ans=0;
    for(int64_t i=N-1;0<=i;i--){
    int64_t b=s.at(i)-'0';
      if(b==0 || b==5)ans+=i+1;
    }cout<<ans<<endl;
   }else{
  map<int64_t,int64_t>M;M[0]=1;
    int64_t a=1; int64_t c=0;
    for(int64_t i=N-1;0<=i;i--){
    int64_t b=s.at(i)-'0';
      c+=b*a;c%=P;
      if(!M.count(c))M[c]=1;
      else
        M[c]++;
      a=(a*10)%P;
    }int64_t ans=0;
    for(auto p:M){
    int64_t v=p.second;
      ans+=(v*(v-1))/2;
    }cout<<ans<<endl;
  }
  return 0;
}