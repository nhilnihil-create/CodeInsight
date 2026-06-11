#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t Q=1000000007,A=1,N,Z=0;
  cin>>N;
  vector<int64_t> p(N);
  for(int i=0;i<N;i++){
    cin>>p[i];
  }
  for(int j=0;j<70;j++){
    int64_t M=0;
    for(int i=0;i<N;i++){
      if(p[i]%2==0){
        M++;
      }
      p[i]/=2;
    }
    Z=(Z+((M*(N-M))%Q)*A)%Q;
    A=(A*2)%Q;
  }
  cout<<Z<<endl;
}

