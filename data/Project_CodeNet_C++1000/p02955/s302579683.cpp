#include <bits/stdc++.h>
using namespace std;
int main(){
int64_t N,K;
  cin>>N>>K;
  vector<int64_t> p(N);
  int64_t S=0;
  for(int i=0;i<N;i++){
    cin>>p[i];
    S+=p[i];
  }
  priority_queue<int64_t> pq;
  for(int i=1;i*i<=S;i++){
    if(S%i==0){
      pq.push(i);
      pq.push(S/i);
    }
  }
  while(true){
    int64_t a=pq.top();
    pq.pop();
    int64_t A=0;
    vector<int64_t> q(N,-1);
    for(int i=0;i<N;i++){
      A+=p[i]%a;
      q[i]*=p[i]%a;
    }
    sort(q.begin(),q.end());
    int64_t B=A/a;
    for(int i=0;i<B;i++){
      A+=q[i];
    }
    if(K>=A){
      cout<<a<<endl;
      break;
    }
  }
}