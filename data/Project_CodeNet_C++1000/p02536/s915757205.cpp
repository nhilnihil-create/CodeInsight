#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;


int main(){
  int n,m;
  cin >> n >> m;
  dsu ds(n);

  for(int i=0;i<m;++i){
    int a,b;
    cin >> a >> b;
    a--;
    b--;
    ds.merge(a,b);
  }
  int ans=0;
  for(int i=0;i<n;++i){
    if(!ds.same(0,i)){
      ds.merge(0,i);
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
