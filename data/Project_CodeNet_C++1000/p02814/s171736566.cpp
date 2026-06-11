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
#define mod 1000000007
#define INF2 1000000000000000000
#define int long long

int gcd(int a, int b) {
    if(b > a) return gcd(b, a);
    else if(b == 0) return a;
    else return gcd(b, a % b);
}

signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    int a[100010];
    rep(i, N) cin >> a[i];
    int k = 0;
    while(((a[0] >> k) << k) == a[0]) k++;
    rep(i, N) {
        int tmp = 0;
        while(((a[i] >> tmp) << tmp) == a[i]) tmp++;
        if(k != tmp) {
            cout << 0 << endl;
            return 0;
        }
    }
    int L = a[0];
    rep(i, N) {
        L = L * a[i] / gcd(L, a[i]);
        if((M + L/2) / L == 0) {
            cout << 0 << endl;
            return 0;
        }
    }
    cout << (M + L/2) / L << endl;




    return 0;
}
