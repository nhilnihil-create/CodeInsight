#include <bits/stdc++.h>
using namespace std;
int main(){
  int N,M;cin>>N>>M;
  priority_queue<int>A;
  for(int i=0;i<N;i++){int a;cin>>a;A.push(a);}
  for(int i=0;i<M;i++){
    long long a=A.top();
    A.pop();
    A.push(a/2);
  }
  long long ans=0;
  for(int i=0;i<N;i++){ans+=A.top();A.pop();}
  cout<<ans<<endl;
}