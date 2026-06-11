#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
 
int main(){
  int N;
  cin>>N;
  vector<int> a(N);
  vector<int> b(N);
  vector<int> c(N);
  rep(i,N) cin>>a[i];
  rep(i,N) cin>>b[i];
  rep(i,N) c[i]=i+1; 
  map<vector<int>, int> mp;
  do{
    mp[c]=mp.size();
  } while (next_permutation(c.begin(),c.end()));
  int ans=abs(mp[a]-mp[b]);
  cout<<ans<<endl;
}