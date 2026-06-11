#include<bits/stdc++.h>
using namespace std;

int main(){
  int K,N;
  cin >> K >> N;
  vector<long long> A(2*N);
  for(int i=0;i<N;i++){
    cin >> A.at(i);
    A.at(i+N)=A.at(i)+K;
  }
  long long mincost=1e9;
  for(int i=0;i<N;i++){
    long long cost=A.at(i+N-1)-A.at(i);
    mincost=min(mincost,cost);
  }
  cout << mincost << endl;
}