#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,K;
  int64_t Z=0;
  cin>>N>>K;
  vector<int> p(N);
  for(int i=0;i<N;i++){
    cin>>p[i];
    p[i]--;
  }
  vector<int> q(N+1);
  map<int,int> m;
  m[0]=1;
  for(int i=0;i<N;i++){
    int j=i+1-K;
    if(j>=0){
      m[q[j]]--;
    }
    q[i+1]=(q[i]+p[i])%K;
    if(m.count(q[i+1])){
      m[q[i+1]]++;
    }
    else{
      m[q[i+1]]=1;
    }
    Z+=m[q[i+1]]-1;
  }
  cout<<Z<<endl;
}