#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr long long MOD = 1000000007;
constexpr long long INF = 1LL << 60;
const long double PI = acosl(-1.0);
constexpr long double EPS = 1e-11;
template<class T> inline bool chmin(T& a, T b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}
template<class T> inline bool chmax(T& a, T b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}
ll n;
void dfs(string s,char t,ll i) {
    if (i == n){
        cout << s << endl;
    }
    else {
        for (char k = 'a'; k <= t;k++){
			char x;
            if (k == t) x = t + 1;
			else
                x = t;
            dfs(s + k, x, i + 1);
        }
    }
}
int main(){
    cin >> n;
    dfs("",'a',0);
}