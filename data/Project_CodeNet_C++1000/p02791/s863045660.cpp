#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(v) v.begin(),v.end()
using namespace std;
typedef long long ll;
 
int main(){
  int N;
  cin>>N;
  vector<int> P(N);
  int ans=0;
  int mi=10000000;
  rep(i,N) cin>>P[i];
  rep(i,N){
    if(P[i]<mi){
      ans++;
    }
    mi=min(P[i],mi);
  }
  cout<<ans<<endl;
}   