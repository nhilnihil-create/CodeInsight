#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N,Q;
  ll K;
  cin>>N>>K>>Q;
  
  int x;
  vector<int> num(N, 0);
  for(int i=0; i<Q; i++){
    cin>>x;
    num.at(x-1)++;
  }
  ll y = Q-K;
  for(int i=0; i<N; i++){
    if(num.at(i)>y) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
  }
}