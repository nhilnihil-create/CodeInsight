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
    ll l = 0, r = n-1, cnt = 0;
    while(r-l>=1){
        while(s.at(l)=='R'){
            l++;
            if(l>=n) goto aa;
        }
        s.at(l) = 'R';
        while(s.at(r) == 'W'){
            r--;
        	if(r<0) goto aa;
        }
        s.at(r) = 'W';
        if(r-l<1) break;
      	cnt++;
        //cout << s << endl;
      	//cout << l << " " << r << endl;
    }
    aa:
    cout << cnt << endl;
    return 0;
}