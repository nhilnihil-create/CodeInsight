#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin>>N;
  long double sum=0;
  for(int i=0;i<N;i++){
    long double A;
    cin>>A;
    sum+=1.0/A;
  }
  cout<<fixed<<setprecision(10)<<1.0/sum<<endl;
      
}