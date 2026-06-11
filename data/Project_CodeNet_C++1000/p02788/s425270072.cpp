#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t N,D,A;
  cin>>N>>D>>A;
  vector<pair<int64_t,int64_t>> p(N);
  vector<int64_t> q(N+1);
  for(int i=0;i<N;i++){
    int64_t a,b;
    cin>>a>>b;
    p[i]=make_pair(a,b);
    q[i]=a;
  }
  q[N]=167167167167;
  sort(p.begin(),p.end());
  sort(q.begin(),q.end());
  vector<int64_t> kez(N+1);
  int64_t Z=0;
  for(int i=0;i<N;i++){
    int64_t X,H;
    tie(X,H)=p[i];
    H-=kez[i];
    if(H>0){
      int64_t L=X+2*D+1;
      int b=lower_bound(q.begin(),q.end(),L)-q.begin();
      int64_t Q=(H-1)/A+1;
      Z+=Q;
      kez[i]+=Q*A;
      kez[b]-=Q*A;
    }
    kez[i+1]+=kez[i];
  }
  cout<<Z<<endl;

    
}