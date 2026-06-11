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
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    int L = C * D / gcd(C, D);
    int ans = B - A + 1;
    ans -= B / C - (A - 1) / C;
    ans -= B / D - (A - 1) / D;
    ans += B / L - (A - 1) / L;
    cout << ans << endl;


    return 0;
}
