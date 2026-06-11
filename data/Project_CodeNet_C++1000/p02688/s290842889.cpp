#include <bits/stdc++.h>
using namespace std;
 
int main() {
  long long N,K,D;
  cin>>N>>K;
  
  set<long long> T;
  long long count=0;
  
  for(long long i=0;i<K;i++){
    long long D;
    cin>>D;
    for(long long k=0;k<D;k++){
      long long A;
      cin>>A;
      T.insert(A);
    }
  }
  
  for(long long p=1;p<=N;p++){
    if(T.count(p)) count++;
  }
  cout<<N-count;
}