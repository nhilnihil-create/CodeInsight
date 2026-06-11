#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;cin>>N;
  long ans=0;
 // vector<int> P(N);
  if(N==1) goto shutsuryoku;
  //この下はN>=2で考えていい
//  for(int i=0;i<N-1;i++) P.at(i)=i+2;
//  P.at(N-1)=1;
//  for(int i=0;i<N;i++) ans += i%P.at(i);
  for(int i=1;i<N;i++) ans +=i;
shutsuryoku:
  cout<<ans<<endl;
}