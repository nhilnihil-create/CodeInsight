#include<bits/stdc++.h>
using namespace std;

int main() {
  int N;cin>>N;
  vector<int> A(N);
  vector<int> ans(N);
  for(int i=0;i<N;i++) cin>>A.at(i);
  int k=0;
  int l=A.at(0)-k;
  for(int i=1;i<N;i++) l=A.at(i)-l;
  k=k/2+l/2;
  ans.at(0)=2*k;
  for(int j=1;j<N;j++){
    k=A.at(j-1)-k;
    ans.at(j)=2*k;
  }
  for(int k=0;k<N;k++) cout<<ans.at(k)<<" ";
}
