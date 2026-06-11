#include <bits/stdc++.h>
#define rep(i,n) for (int i =0;i<n;i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
  int n;
  cin >> n;
  vector <int> x(n);
  vector <int> l(n);
  vector <P> p(n);
  rep(i,n)cin >> x[i] >> l[i];
  rep(i,n){
    p[i]=P(x[i]+l[i],x[i]-l[i]);
  }
  sort(p.begin(),p.end());
  int right=p[0].first;
  int ans=1;
  for(int i=1;i<n;i++){
    if(p[i].second<right)continue;
    right=p[i].first;
    ans++;
  }
  cout << ans << endl;
}
