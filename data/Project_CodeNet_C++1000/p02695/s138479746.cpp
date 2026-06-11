#include <bits/stdc++.h>
using namespace std;

long n,m,q,ans=0;
vector<long> a(50);
vector<long> b(50);
vector<long> c(50);
vector<long> d(50);

void zentansaku(vector<long> x) {
  if(x.size()-1==n) {
    long score=0;
    for(long i=0;i<q;i++) {
      if(x[b[i]]-x[a[i]]==c[i]) score+=d[i];
    }
    ans=max(ans,score);
    return;
  }
  for(long i=x.back();i<=m;i++){
    vector<long> y=x;
    y.push_back(i);
    zentansaku(y);
  }
  return;
}

int main() {
  cin >> n >> m >> q;
  for(long i=0;i<q;i++) cin >> a[i] >> b[i] >> c[i] >> d[i];
  zentansaku({1});
  cout << ans << endl;
}