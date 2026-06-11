#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <algorithm>
#define rep(i,w) for (int i = 0;i < (w); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int INF = 1e9;

int main(){
  int n,m;cin >> n >> m;

vector<P> opt(n);
rep(i,n) {
  int a,b;cin >> a >> b;
  opt[i] = make_pair(a,b);
}
sort(opt.begin(),opt.end());

multiset<int> s;
int ind = 0;
int ans = 0;
for(int i = m-1;i >= 0;i--){
  while(opt[ind].first<=m-i && ind < opt.size()) {
    s.insert(opt[ind].second);
    ind++;
  }
  if(s.size()){
    ans += *(--s.end());
    //cout << ans << endl;
    s.erase(--s.end());
  }
}

cout << ans << endl;




}