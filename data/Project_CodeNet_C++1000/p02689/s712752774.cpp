#include<bits/stdc++.h>
using namespace std;
int main(){
  int N,M;
  cin>>N>>M;
  vector<int> H(N);
  vector<bool> A(N,true);
  for(int &i:H)
    cin>>i;
  while(M--){
    int a,b;
    cin>>a>>b;
    a--,b--;
    if(H[a]>=H[b])
      A[b]=false;
    if(H[a]<=H[b])
      A[a]=false;
  }
  int j=0;
  for(bool bo:A)
    if(bo)
      j++;
  cout<<j<<endl;
}