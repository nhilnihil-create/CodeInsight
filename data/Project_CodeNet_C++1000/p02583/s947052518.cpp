#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(x) begin(x), end(x)
using namespace std;
typedef long long ll;
typedef pair <int,int> P;

int main(){
  int n;
  cin>>n;
  int l[105];
  rep(i,n) cin>>l[i];
  sort(l,l+n);

  int ans=0;
  rep(i,n) rep(j,i) rep(k,j){
    if(l[i]==l[j]||l[j]==l[k]) continue;
    if(l[i]<l[j]+l[k]){
      ans++;
    }
  }
  cout<<ans<<endl;
  return 0;
}
