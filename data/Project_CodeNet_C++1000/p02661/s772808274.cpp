#include <bits/stdc++.h>
using namespace std;
int main(){
  int N; cin>>N;
  vector<int>A(N);
  vector<int>B(N);
  for(int i=0;i<N;i++)cin>>A[i]>>B[i];
  sort(A.begin(),A.end());
  sort(B.begin(),B.end());
  if(N%2==1)cout<<B[N/2]-A[N/2]+1<<endl;
  else cout<<(B[N/2-1]+B[N/2])-(A[N/2-1]+A[N/2])+1<<endl;
}