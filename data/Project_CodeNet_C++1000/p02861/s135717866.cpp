#include<bits/stdc++.h>
using namespace std;
int main(){
  long N;cin>>N;
  vector<long>X(N),Y(N);
  for(long i=0;i<N;i++)cin>>X[i]>>Y[i];
  vector<long>P(N);for(long i=0;i<N;i++)P[i]=i;
  double ans=0;long n=0;
  do{
    n++;
    for(long i=1;i<N;i++)ans+=sqrt((X[P[i]]-X[P[i-1]])*(X[P[i]]-X[P[i-1]])+(Y[P[i]]-Y[P[i-1]])*(Y[P[i]]-Y[P[i-1]]));
  }while(next_permutation(P.begin(),P.end()));
  cout<<fixed<<setprecision(12)<<ans/n<<endl;
}

/*



*/