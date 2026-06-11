#include<bits/stdc++.h>
using namespace std;
int main(){
  long N,Q;cin>>N>>Q;
  vector<vector<long>>A(N);
  for(long i=0;i<N-1;i++){
    long a,b;cin>>a>>b;
    A[a-1].push_back(b-1);
    A[b-1].push_back(a-1);
  }
  
  vector<long>X(N),Y(N);
  for(long i=0;i<Q;i++){
    long p,x;cin>>p>>x;
    X[p-1]+=x;
  }
  queue<long>q;q.push(0);
  vector<bool>used(N);used[0]=1;
  while(q.size()){
    long p=q.front();q.pop();
    Y[p]+=X[p];
    for(long n:A[p])if(used[n]==0){
      q.push(n);
      used[n]=1;
      X[n]+=X[p];
    }
  }
  for(long i=0;i<N;i++)cout<<Y[i]<<" ";
  
}

/*




*/

