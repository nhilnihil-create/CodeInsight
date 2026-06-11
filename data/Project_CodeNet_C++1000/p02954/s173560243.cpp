#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  string S;
  cin>>S;
  int N=S.size();
  vector<pair<char,int>> A={make_pair('a',0)};
  for(char c:S){
    if(A.back().first==c)A.back().second++;
    else A.push_back({c,1});
  }
  A.erase(A.begin());
  vector<int> B(N);
  int M=A.size(),sum=0;
  for(int i=0;i<M;i+=2){
    sum+=A[i].second;
    B[sum-1]+=(A[i].second+1)/2+A[i+1].second/2;
    B[sum]+=A[i].second/2+(A[i+1].second+1)/2;
    sum+=A[i+1].second;
  }
  for(int i=0;i<N;i++)cout<<B[i]<<(i==N-1?'\n':' ');
}