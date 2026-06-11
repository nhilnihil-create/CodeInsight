#include<bits/stdc++.h>
using namespace std;

int main(){

  int i, N, ans=0; cin>>N;
  int a[N];
  for(i=0; i<N; i++) cin>>a[i];
  for(i=0; i<N; i++) ans=ans^a[i];
  
  for(i=0; i<N; i++){
    cout<<(ans^a[i])<<" ";
  }
  cout<<endl;
  return 0;
}
