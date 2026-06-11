#include <bits/stdc++.h>
using namespace std;

int gcd(long long a, long long b) {
  if(a < b) return gcd(b, a);
  long long r;
  while ((r=a%b)) {
    a = b;
    b = r;
  }
  return b;
}

int main(){
  long long N,M;
  cin >> N >> M;
  long long temp;
  long long B[N];
  long long MB=1;
  for(int i=0;i<N;i++){
    cin>>temp;
    B[i]=temp/2;
    MB=(MB*B[i])/gcd(MB,B[i]);
    if(MB>M){
      cout<<0<<endl;
      return 0;
    }
  }
  //cout<<MB<<endl;
  for(int i=0;i<N;i++){
    if((MB/B[i])%2==0){
      cout<<0<<endl;
      return 0;
    }
  }
  
  cout<<M/MB-M/(2*MB)<<endl;
  return 0;
}