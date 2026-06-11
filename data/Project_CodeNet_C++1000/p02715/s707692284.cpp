#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<iomanip>
#include<cmath>

#define REP(i,n) for (int i = 0; (i) < (n); ++ (i))
#define FOR(i,n) for (int i = 1; (i) <= (n); ++ (i))
#define dump(x)  cout << #x << " = " << (x) << endl;
#define pb push_back
#define int long long

const int INF = 1e18;
const int MOD = 1e9+7;
//const lint LINF = 1e18;
const double eps = 0.000000001;//もとの値の10^(-16)まで

using namespace std;

//typedef pair<int, int> P;
//priority_queue< P, vector<P>, greater<P> > q;//ダイクストラの時、greaterで小さい順
//cout << fixed << setprecision(10) << ans << endl;
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int mypow(int _x, int _n){
	int ret = 1;
	while(0 < _n){
		if((_n % 2) == 0){
			_x *= _x;
            _x %= MOD;
			_n >>= 1;
		}
		else{
			ret *= _x;
            ret %= MOD;
			--_n;
		}
	}
	return ret;
}

int ans1[200000];

signed main(){
    int n,k;
    cin >> n >> k;
    int ans = 0;
    for(int i = k;i>0;i--){
        int now = i;
        int nn = k/now;
        int n3 = mypow(nn,n);
        while(now <= k){
            n3 += MOD;
            n3 -= ans1[now];
            n3 %= MOD;
            now += i;
        }
        ans1[i] = n3;
        ans += n3 * i;
        ans %= MOD; 
    }
    cout << ans << endl;
    return 0;
}