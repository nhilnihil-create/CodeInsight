#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,a,b) for(int i=(a); i<(b); i++)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
typedef long long ll;
typedef pair<int, int> pii;

vector< int > divisor(int n) {
  vector< int > ret;
  for(int i = 1; i * i <= n; i++) {
    if(n % i == 0) {
      ret.push_back(i);
      if(i * i != n) ret.push_back(n / i);
    }
  }
  sort(rbegin(ret), rend(ret));
  return (ret);
}

int main(){
    int n, k; cin >> n >> k;
    vector<int> a(n);
    int sum = 0;
    rep(i,n) {
        cin >> a[i];
        sum += a[i];
    }
    auto v = divisor(sum);
    rep(i, (int)v.size()){
        vector<pii> diff;
        int ofs = 0;
        rep(j,n){
            int q = a[j] / v[i];
            int ne = q*v[i] - a[j];
            int po = v[i]*(q + 1) - a[j];
            if(ne < 0) diff.push_back(make_pair(po, ne));
            ofs += ne;
        }
        if(diff.empty()){
            cout << v[i] << endl;
            return 0;
        }
        sort(ALL(diff));
        int cnt = -ofs / v[i];
        if(cnt > n) break;
        int num = 0;
        rep(i, cnt){
            num += diff[i].first;
        }
        if(num <= k){
            cout << v[i] << endl;
            return 0;
        }
    }
}
