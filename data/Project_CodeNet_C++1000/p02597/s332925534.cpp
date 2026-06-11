#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const ll mod = 1000000007;
const ll INF = 1001001001;
const ll LINF = 1001001001001001001;

void prvec(vector<ll> vec){
    ll n = vec.size();
    rep(i,n) cout << i << " " << vec.at(i) << "\n";
}

void pr2d(vector<vector<ll>> vvec){
    ll h = vvec.size();
    ll w = vvec.at(0).size();
    rep(i,h){
        rep(j,w){
            cout << vvec.at(i).at(j) << " ";
        }
        cout << "\n";
    }
}

int main(){
    ll n ; cin >> n;
    string s; cin >> s;
    ll r[n+1],w[n+1];
    r[0] = 0, w[0] = 0;
    if(s.at(0)=='R') r[0]++; else w[0]++;
    for(int i=1;i<n;i++){
        if(s.at(i)=='R'){
            r[i] = r[i-1] + 1;
          	w[i] = w[i-1];
        }else{
          	r[i] = r[i-1];
            w[i] = w[i-1] + 1;
        }
    }
  	r[n] = r[n-1], w[n] = w[n-1];
    ll ans = INF;
    rep(i,n+1){//i番目の左側に仕切りがある
        //仕切りより左側にあるwの数と仕切りより右側にあるrの数
        if(i==0){
          ans = min(ans,r[n-1]);
          //cout << ans << endl;
          continue;
        }
      	ans = min(ans,max(w[i-1],r[n-1]-r[i-1]));
      	//cout << i << " " << ans << endl;
      	//cout << w[i-1] << r[n-1] << r[i-1] << endl;
    }
    cout << ans << endl;
    return 0;
}