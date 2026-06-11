#include <bits/stdc++.h>
using namespace std;
int main(){
  long long N,K;
  cin>>N>>K;
  long long a,b;
  a=N%K;
  b=K-a;
  if(a>b){
  cout<<b<<endl;
  }

  else{
  cout<<a<<endl;
  }
  
}