#include <bits/stdc++.h>
using namespace std;
const long long int mod=998244353;
int main(){
  long long int N,x=0;cin>>N;
  vector<long long int>D(N);
  cin>>D.at(0);
  if(D.at(0)==0){ 
    if(N==1)x=1;
    else{ 
      for(long long int i=1;i<N;i++)cin>>D.at(i);
      sort(D.begin(),D.end());
      if(D.at(1)!=0){
        x=1;
        vector<long long int>C(D.at(N-1));
        for(long long int i=0;i<D.at(N-1);i++)
          C.at(i)=upper_bound(D.begin(),D.end(),i)-lower_bound(D.begin(),D.end(),i);
        for(long long int i=1;i<N;i++)
          x=x*C.at(D.at(i)-1)%mod;
      }
    }
  }
  printf("%lld\n",x);
}