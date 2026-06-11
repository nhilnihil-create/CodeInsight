#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
int main(){
  long long N;
  cin>>N;
  if(N%2==1) cout<<0<<endl;
  else{
    N=N/2;
    long long answer=0;
    long long k=5;
    while(k<=N){
      answer+=N/k;
      k=k*5;
    }
    cout<<answer<<endl;
  }
  
return 0;
}