#include<bits/stdc++.h>
using namespace std;
int main(){
  long N,K;cin>>N>>K;
  vector<long>A(N);long S=0;
  for(long i=0;i<N;i++){cin>>A[i];S+=A[i];}
  
  vector<long>D;
  for(long i=1;i*i<=S;i++)if(S%i==0){D.push_back(i);D.push_back(S/i);}
  sort(D.begin(),D.end(),greater<long>());  
  for(auto d:D){
    vector<long>R;long sr=0;
    for(long i=0;i<N;i++)if(A[i]%d!=0){R.push_back(A[i]%d);sr+=A[i]%d;}
    sort(R.begin(),R.end());
    long k=0;
    for(long i=0;i<R.size()-sr/d;i++)k+=R[i];
    if(k<=K){cout<<d;return 0;}
  }
}

