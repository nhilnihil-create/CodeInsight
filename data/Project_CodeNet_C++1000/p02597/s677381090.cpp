#include<iostream>
#include<vector>
using namespace std;

int main() {
  int N,i;
  string S;
  cin>>N>>S;
  vector<int> R(N+1,0);
  for (i=0;i<N;i++)
    R[i+1]=R[i]+(S[i]=='R'?1:0);
  cout<<R[N]-R[R[N]]<<endl;
  return 0;
}
