#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin>>N;
  vector<double>A(N);
  for(int i=0;i<N;i++)cin>>A[i];
  sort(A.begin(),A.end());
  double ans=(A[0]+A[1])/2;
  for(int i=2;i<N;i++)ans=(A[i]+ans)/2;
  cout<<ans<<endl;
}