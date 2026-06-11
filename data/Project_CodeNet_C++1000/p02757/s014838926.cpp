#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int N,P;
  string S;
  cin>>N>>P>>S;
  reverse(S.begin(),S.end());
  if(P==2 || P==5){
    int j=0;
    for(int i=0;i<N;i++)
      if((S[i]-'0')%P==0)
        j+=N-i;
    cout<<j<<endl;
    return 0;
  }
  vector<int> A(N+1,0);
  int k=1;
  for(int i=1;i<=N;i++){
    A[i]=(A[i-1]+(S[i-1]-'0')*k)%P;
    k=k*10%P;
  }
  map<int,int> B;
  for(int i:A)
    B[i]++;
  int i=0;
  for(pair<int,int> p:B)
    i+=p.second*(p.second-1)/2;
  cout<<i<<endl;
}