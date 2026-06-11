#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
int main(){
  int N,V,P;
  long long M;
  cin>>N>>M>>V>>P;
  long long A[100000],emp[100000];
  for(int i=0;i<N;i++) cin>>A[i];
  sort(A,A+N);
  emp[N-P]=0;
  for(int i=N-P-1;i>=0;i--){
    emp[i]=A[N-P]-A[i];
    emp[i]+=emp[i+1];
  }
  int answer=P;
  for(int i=0;i<N-P;i++){
    if(A[N-P]-A[i]<=M){
      long long a=A[i]+M;
      long long vote=(V-P-i)*M;
      if(emp[i+1]+(N-P-i)*(a-A[N-P])>=vote){
        answer=N-i;
        break;
      }
    }
  }
  cout<<answer<<endl;
  
  return 0;
}