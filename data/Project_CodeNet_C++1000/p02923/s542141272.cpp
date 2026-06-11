#include <bits/stdc++.h>
using namespace std;

int main(){
  long long N;
  cin>>N;
  long long j=0,k=0,l=0;
  for(long long i=0;i<N;i++){
    long long H;
    cin>>H;
    if(k>=H){
      l++;
    }
    else{
      j=max(j,l);
      l=0;
    }
    k=H;
  }
  cout<<max(j,l)<<endl;
}