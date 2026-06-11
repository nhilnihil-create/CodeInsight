#include <bits/stdc++.h>
using namespace std;


int main() {
  int N,K,Q;
  cin>>N>>K>>Q;
  
  vector<int> vec(N+1,Q);
  
  for(int i=0;i<Q;i++){
    int a;
    cin>>a;
    vec.at(a)-=1;
  }
  for(int i=1;i<=N;i++){
    if(vec.at(i)<K) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
  }
  
}