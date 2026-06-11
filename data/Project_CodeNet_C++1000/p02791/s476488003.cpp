#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;cin>>N;
  int A[N];
  for(int i=0;i<N;i++){
    cin>>A[i];
  }
  int m=1000000;
  int ans=0;
  for(int i=0;i<N;i++){
    m=min(m,A[i]);
    if(m==A[i]) ans++;
  }
  cout<<ans<<endl;
}