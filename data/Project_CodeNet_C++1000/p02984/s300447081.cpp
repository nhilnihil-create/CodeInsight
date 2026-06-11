#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int N,g=0;
  cin>>N;
  vector<int> A(N);
  for(int &i:A){
    cin>>i;
    g+=i;
  }
  vector<int> B(N);
  for(int i=1;i<N;i+=2)
    B[0]+=A[i];
  for(int i=1;i<N;i++)
    B[i*2%N]=B[(i*2-2+N)%N]+A[(i*2-2)%N]-A[(i*2-1+N)%N];
  for(int i=0;i<N;i++){
    cout<<g-B[i]*2;
    if(i==N-1)
      cout<<endl;
    else
      cout<<' ';
  }
}