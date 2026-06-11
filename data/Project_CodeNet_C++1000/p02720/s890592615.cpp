#include<bits/stdc++.h>
using namespace std;
#define int long long
void a(vector<string> &A,string S,int j,int k){
  if(S.size()==k){
    A.push_back(S);
    return;
  }
  for(int i=-1;i<2;i++)
    if(0<=j+i && j+i<10)
      a(A,S+to_string(j+i),j+i,k);
}
signed main(){
  int K;
  cin>>K;
  vector<string> A(0);
  for(int j=1;j<=10;j++)
    for(int i=1;i<10;i++)
      a(A,to_string(i),i,j);
  cout<<A.at(K-1)<<endl;
}