#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int N;
  cin>>N;
  vector<int> A(N),B(N);
  for(int i=0;i<N;i++)
    cin>>A[i],B[i]=A[i];
  sort(A.begin(),A.end());
  int cnt=0;
  for(int i=0;i<N;i++)
    if(A[i]!=B[i])cnt++;
  puts(cnt<=2?"YES":"NO");
}