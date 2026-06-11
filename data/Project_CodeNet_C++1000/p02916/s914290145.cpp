#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin>>N;
  vector<int> p(N);
  for(int i=0;i<N;i++){
    cin>>p[i];
    p[i]--;
  }
  int Z=0;
  for(int i=0;i<N;i++){
    int a;
    cin>>a;
    Z+=a;
  }
  vector<int> q(N-1);
  for(int i=0;i<N-1;i++){
    cin>>q[i];
  }
  for(int i=0;i<N-1;i++){
    if(p[i]+1==p[i+1]){
      Z+=q[p[i]];
    }
  }
  cout<<Z<<endl;
    
}