#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  vector<int> a(n),b(n);

  rep(i,n) cin >> a[i];
  rep(i,n) cin >> b[i];
  priority_queue<pair<int,int>> pq;
  rep(i,n){
    if(a[i]!=b[i]) pq.push({b[i],i});
  }

  ll ans =0;

  while(!pq.empty()){

    auto cp = pq.top(); pq.pop();
    int val = cp.first;
    int pos = cp.second;

    int pre_pos = pos -1;
    if(pre_pos < 0) pre_pos = n-1;
    int nxt_pos = pos +1;
    if(nxt_pos >= n) nxt_pos = 0;

    if(b[pre_pos]+b[nxt_pos] >= b[pos]){
      cout << -1 << endl;
      return 0;
    }
    int times = max((b[pos]-a[pos])/(b[pre_pos]+b[nxt_pos]),1);
    ans+=times;
    b[pos] -= (b[pre_pos] + b[nxt_pos]) * times;
    if(b[pos]==a[pos]) continue;
    else if(b[pos] < a[pos]){
      cout << -1 << endl;
      return 0;
    }
    pq.push({b[pos],pos});
    // cout << b[pos] << endl;
  }

  cout << ans << endl;


  return 0;
    

}
