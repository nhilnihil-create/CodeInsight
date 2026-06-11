#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <functional>
#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
using namespace std;
#define ll long long int
#define rep(i,n) for( int i = 0; i < n; i++ )
#define rrep(i,n) for( int i = n; i >= 0; i-- )
#define REP(i,s,t) for( int i = s; i <= t; i++ )
#define RREP(i,s,t) for( int i = s; i >= t; i-- )
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define INF 2000000000
#define INF2 1000000000000000000
#define int long long
int mod = 1000000007;
int Mul(int a, int b) {
	return ((a % mod) * (b % mod)) % mod;
}


int square(int x) {
	return (x * x) % mod;
}

int power(int x, int y) {
	if (y == 0) return 1;
	else if (y == 1) return x % mod;
	else if (y % 2 == 0) return square(power(x, y / 2)) % mod;
	else return square(power(x, y / 2)) * x % mod;
}

int Div(int a, int b) {
	return Mul(a, power(b, mod - 2));
}
signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, P;
    string S;
    cin >> N >> P;
    cin >> S;
    if(P == 2 || P == 5) {
        int ans = 0;
        rep(i, N) {
            int num = S[i] - '0';
            if(num % P == 0) ans += i + 1;
        }
        cout << ans << endl;
        return 0;
    }
    mod = P;
    int ans = 0;
    map<int, int> mp;
    int sum = 0;
    rep(i, N) {
        int num = power(10, i) * (S[N - i - 1] - '0') % P;
        sum = (sum + num) % P;
        mp[sum]++;
    }
    sum = 0;
    int num = 0;
    rep(i, N) {
        //cerr << i << " " << sum << " ";
        int k = power(10, i) * (S[N - i - 1] - '0') % P;
        ans += mp[(P - sum) % P];
        sum = (sum - (k) + P*10) % P;
        //sum = (sum * 10) % P;
        num = (num + k) % P;
        mp[num]--;
        //cerr << ans << endl;
    }
    cout << ans << endl;


    return 0;
}
// 3000, 3500,3540, 3543
//       500, 540,   543
//            40,     43
//                     3