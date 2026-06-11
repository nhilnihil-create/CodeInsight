#include<bits/stdc++.h>
using namespace std;
bool cmp(const vector<long>&A,const vector<long>&B){
  for(long i=0;i<A.size();i++)if(A[i]!=B[i])return 0;
  return 1;
}
int main(){
  long N;cin>>N;
  vector<long>X(N),Y(N);
  for(long i=0;i<N;i++)cin>>X[i];
  for(long i=0;i<N;i++)cin>>Y[i];
  vector<long>P(N);for(long i=0;i<N;i++)P[i]=i+1;
  long i=0;
  long a,b;
  do{
    if(cmp(X,P))a=i;
    if(cmp(Y,P))b=i;
    i++;  
  }while(next_permutation(P.begin(),P.end()));
  cout<<abs(a-b)<<endl;
}

/*



*/