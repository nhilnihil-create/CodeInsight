#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(v) v.begin(),v.end()
using namespace std;
typedef long long ll;
 
int main(){
  int N;
  cin>>N;
  vector<int> H(N);
  rep(i,N) cin>>H[i];
  int ans=0;
  int cnt=0;
  for(int i=1;i<N;i++){
    if(H[i]-H[i-1]<=0){
      cnt++;
    }
    if(H[i]-H[i-1]>0){
      ans=max(ans,cnt);
      cnt=0;
    }
  }
  ans=max(ans,cnt);
  cout<<ans<<endl;
}   