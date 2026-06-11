#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int N;
  cin>>N;
  vector<pair<int,int>> A(N);
  for(int i=0;i<N;i++)
    cin>>A[i].second>>A[i].first;
  sort(A.begin(),A.end());
  int t=0;
  for(int i=0;i<N;i++){
    t+=A[i].second;
    if(t>A[i].first){
      puts("No");
      return 0;
    }
  }
  puts("Yes");
}