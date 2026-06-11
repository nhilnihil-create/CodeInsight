#include <bits/stdc++.h>
using namespace std;

int main() {
  long long N;
  cin>>N;
  long long A,B;
  for(long long i=1;i<=sqrt(N)+1;i++){
    if(N%i==0){
      A=i;
      B=N/i;
    }
  }
  cout<<A+B-2<<endl;
}