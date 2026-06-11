#include <bits/stdc++.h>
using namespace std;
int main(){
  long long int m,N;cin>>N;
  vector<long long int>A(N);
  cin>>A.at(0);
  for(int i=1;i<N;i++){
    cin>>m;A.at(i)=A.at(i-1)+m;
  }
  m=fabs(A.at(N-1)-2*A.at(0));
  for(int i=1;i<N;i++){
    long long int f=A.at(i-1),x=A.at(i)-A.at(i-1),b=A.at(N-1)-A.at(i);
    x=fabs(fabs(f-b)-x);
    m=min(m,x);
  }
  cout<<m<<endl;
}