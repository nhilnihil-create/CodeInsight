#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i,s,n) for(int i = s; i < (int)(n); i++)

int main() {
  int n,ans;
  cin >> n;
  ans = n;
  vector<P>data(n);
  rep(i,0,n){
    int x,l;
    cin >> x >> l;
    data[i].second = x-l;
    data[i].first = x+l;
  }
  sort(data.begin(),data.end());
  ll r = data[0].first;
  rep(i,1,n){
    if(data[i].second < r) ans--;
    else r = data[i].first;
  }
  cout << ans << endl;
}