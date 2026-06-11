#include <bits/stdc++.h>
using namespace std;
int main(){
  int N,K;
  cin>>K>>N;
  vector<int> A(N);
  for(int i=0;i<N;i++){
    cin>>A.at(i);
  }
  vector<int> B(N-1);
  for(int i=0;i<N-1;i++){
    B.at(i)=A.at(i+1)-A.at(i);
  }
  B.push_back(K-A.at(N-1)+A.at(0));
  sort(B.begin(),B.end());
  cout<<K-B.at(N-1)<<endl;
}
