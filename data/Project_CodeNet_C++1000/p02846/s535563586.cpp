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

signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T1, T2; cin >> T1 >> T2;
    int A1, A2, B1, B2;
    cin >> A1 >> A2;
    cin >> B1 >> B2;
    if(A1 > B1) {
        swap(A1, B1);
        swap(A2, B2);
    }
    int dA1 = T1 * A1, dA2 = dA1 + T2 * A2;
    int dB1 = T1 * B1, dB2 = dB1 + T2 * B2;
    // cout << dA1 << " " << dA2 << endl;
    // cout << dB1 << " " << dB2 << endl;
    if(dA2 == dB2) {
        cout << "infinity" << endl;
        return 0;
    }
    int diff = dA2 - dB2;
    int ok = -1;
    int ng = 1e+18;
    map<int, int> mp;
    while(abs(ok - ng) > 1) {
        int mid = (ok + ng) / 2;
        double c = T1 * A1 + (diff * (double)mid);
        if(c > 2e+18) ng = mid;
        int dA1 = T1 * A1 + diff * mid, dA2 = dA1 + T2 * A2;
        int dB1 = T1 * B1, dB2 = dB1 + T2 * B2;
        //cerr << mid << " " << dA1 << " " << dB1 << " " << dA2 << " " << dB2 << endl;
        if(dA1 <= dB1 && dA2 >= dB2) {
            ok = mid;
            if(dA1 < dB1 && dA2 >= dB2) {
                mp[mid] = 1;
            }
        }
        else ng = mid;
    }
    cout << max(0LL,ok * 2 + mp[ok]) << endl;


    return 0;
}
// 1 1
// 2 1
// 1 3


// 0 2 3 5 
// 0 1 4 5

// 0 3 4 7
// 0 2 5 7