#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int A,B;
  cin>>A>>B;
  int N=__gcd(A,B),j=1;
  for(int i=2;i*i<N;i++){
    if(N%i==0){
      for(;N%i==0;N/=i){}
      j++;
    }
  }
  if(N!=1)
    j++;
  cout<<j<<endl;
}
