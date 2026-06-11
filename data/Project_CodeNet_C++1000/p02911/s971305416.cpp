#include <bits/stdc++.h>
using namespace std;

int main(){
  long long N,K,Q;
  cin >> N >> K >> Q;
  vector<long long> A(N);
  for(int i=0;i<Q;i++){
    int X;
    cin >> X;
    A[X-1]++;
  }
  for(int i=0; i<N; i++){
    if(K+A[i]-Q > 0){
      cout<<"Yes"<<endl;
    }
    else{
      cout<<"No"<<endl;
    }
  }
}
