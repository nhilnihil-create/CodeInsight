#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin>>N;
  vector<int> p(N);
  vector<pair<int,int>> q(N-1);
  for(int i=0;i<N-1;i++){
    int a;
    cin>>a;
    q[i]=make_pair(a,i);
  }
  sort(q.begin(),q.end());
  for(int i=N-2;i>=0;i--){
    int a,b;
    tie(a,b)=q[i];
    p[b]=a;
    p[b+1]=a;
  }
  int Z=0;
  for(int i=0;i<N;i++){
    Z+=p[i];
  }
  cout<<Z<<endl;
}