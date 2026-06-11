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
#define PI acos(0)

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int a, b, x;
    cin >> a >> b >> x;
    if(a * a * b <= x * 2) {
        cerr << a << " " <<2*(a*a*b-x)/(a * a+0.0)<< endl;
        cout << fixed << setprecision(12) << atan2(2*(a*a*b-x)/(a * a+0.0), a) * 180.0/(2*PI) << endl;
    } else {
        cout << fixed << setprecision(12) << 90.0 - atan2(x*2/(a * b + 0.0),b) * 180.0/(2*PI) << endl;
    }

    return 0;
}
