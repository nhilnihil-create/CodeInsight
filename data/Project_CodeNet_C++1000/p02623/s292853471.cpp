#include<bits/stdc++.h>
#define int long long
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define repa(i, s, n) for(int i = s; i < (int)n; i++)
using namespace std;
using ll = long long;
typedef vector<int> vi;
typedef pair<int, int> P;
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define MOD 1000000007
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
int n, m, k, rest;
vi a, b, a_sum, b_sum;
bool isOK(int index, int key){
	if(key >= b_sum[index]) return true;
	else return false;
}

int nibutan(int key){
	int ng = m+1;
	int ok = -1;
	while(abs(ok - ng) > 1){
		int mid = (ok + ng) / 2;
		if(isOK(mid, key)) ok = mid;
		else ng = mid;
	}
	return ok /*=条件を満たすギリギリを返す*/;
    /* 満たさないものを求めるときは1を加減算する */
}

signed main(){
    int ans = 0;
    cin >> n >> m >> k;
    a.resize(n);
    b.resize(m);
    a_sum.resize(n+1);
    b_sum.resize(m+1);
    rep(i, n){
        cin >> a[i];
        a_sum[i+1] = a[i] + a_sum[i];
    }
    /* rep(i, n) cin >> a[i]; */
    rep(i, m){
        cin >> b[i];
        b_sum[i+1] = b[i] + b_sum[i];
    }

    // aをi冊読む
    rep(i, n+1){
        if(a_sum[i] > k) continue;
        rest = k - a_sum[i];
        /* cout << i << " " << nibutan(rest) << endl; */
        chmax(ans, nibutan(rest) + i);
    }

    cout << ans << endl;
}