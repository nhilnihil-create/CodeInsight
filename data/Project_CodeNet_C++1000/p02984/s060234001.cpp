#include <bits/stdc++.h> 

using namespace std;
using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>;

#define INF LONG_MAX
#define MOD 1000000007
#define rng(a) a.begin(),a.end()
#define rrng(a) a.end(),a.begin()
#define endl "\n"

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N;
  cin>>N;
  vector<int>A(N);
  for(int i=0;i<N;i++)cin>>A[i];

  int z=0;
  for(int i=0;i<N;i++){
    if(i%2)z-=A[i];
    else z+=A[i];
  }

  int index=0;
  if(z<0)z*=-1,index=1;

  vector<int>ans(N);
  ans[index]=z;

  if(index==0){
    for(int i=1;i<N;i++){
      ans[i]=2*A[i-1]-ans[i-1];
    }
  }
  else{
    ans[0]=A[0]-ans[1]/2;
    for(int i=2;i<N;i++){
      ans[i]=2*A[i-1]-ans[i-1];
    }
  }

  for(auto it:ans)cout<<it<<" ";
  cout<<endl;
  return 0;
}
