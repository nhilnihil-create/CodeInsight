#include<bits/stdc++.h>
using namespace std;
int main(){
  int N,K;
  cin>>N>>K;
  int ans=0;
  int c[N];
  for(int i=0; i<N; i++) cin>>c[i];
  sort(c,c+N);
  for(int i=0; i<K; i++) ans+=c[i];
  cout<<ans<<endl;
}