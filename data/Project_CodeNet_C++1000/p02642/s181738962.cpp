#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;cin>>N;
  vector<int>A(N);
  vector<bool>B(1000001,true);
  vector<int>D(1000001,0);
  for(int i=0;i<N;i++){
    cin>>A[i];
    D[A[i]]++;
    if(B[A[i]]==false||D[A[i]]>1)continue;
    for(int j=2;A[i]*j<=1000000;j++)B[j*A[i]]=false;
  }
  int ans=0;
  for(int i=0;i<N;i++)if(B[A[i]]&&D[A[i]]<2)ans++;
  cout<<ans<<endl;
}