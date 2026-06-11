#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin>>N;
  vector<long long> A(N),B(N);
  for(int i=0;i<N;i++){
    cin>>A.at(i);
  }
  B.at(0)=A.at(0);
  for(int i=1;i<N;i++){
    B.at(i)=B.at(i-1)+A.at(i);
  }
  long long all=B.at(N-1);
  long long ans=2100000000LL;
  for(int i=0;i<N-1;i++){
    ans=min(ans,abs(all-B.at(i)*2LL));
  }
  cout<<ans<<endl;
}
