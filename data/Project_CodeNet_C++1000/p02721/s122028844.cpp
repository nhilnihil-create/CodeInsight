#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
    int n, k, c;
    string s;
    cin >> n >> k >> c >> s;
    vector<int> l(n, 0), r(n, 0);
    int cnt = 0;
    rep(i,n){
        if(s[i] == 'o'){
            l[i] = ++cnt;
            i += c;
        }
        if(cnt == k) break;
    }
    for(int i = n-1; i >= 0; --i){
        if(s[i] == 'o'){
            r[i] = cnt--;
            i -= c;
        }
    }
    rep(i,n){
        if(l[i] == r[i] && l[i] != 0) cout << i+1 << endl;
    }
	return 0;
}