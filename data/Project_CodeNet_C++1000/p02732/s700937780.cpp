#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int N;
  cin>>N;
  vector<int> A(N);
  for(int &i:A)
    cin>>i;
  map<int,int> B;
  for(int i:A)
    B[i]++;
  int k=0;
  for(pair<int,int> p:B)
    k+=(p.second-1)*p.second/2;
  for(int i=0;i<N;i++){
    cout<<k-(B[A[i]]-1)<<endl;
  }
}