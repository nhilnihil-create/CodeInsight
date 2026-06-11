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

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N; cin >> N;
    int A[100010];
    rep(i, N) cin >> A[i];
    sort(A, A + N, greater<int>());
    if(N == 2) {
        cout << A[0] - A[1] << endl;
        cout << A[0] << " " << A[1] << endl;
        return 0;
    }
    int ans = A[0];
    int num1 = -INF, num2 = -INF;
    if(A[N - 1] >= 0) {
       
        num1 = A[N - 1];
        num2 = A[N - 2];
        A[N - 2] = A[N - 1] - A[N - 2];
        N--;
    }
    rep(i, N - 1) {
        ans += abs(A[i + 1]);
    }
    cout << ans << endl;
    if(num1 != -INF) {
        cout << num1 << " " << num2 << endl;
    }
    int x = A[0], y = A[N - 1];
    rep(i, N - 2) {
        if(A[i + 1] > 0) {
            cout << y << " " << A[i + 1] << endl;
            y -= A[i + 1];
        } else {
            cout << x << " " << A[i + 1] << endl;
            x -= A[i + 1];
        }
    }
    cout << x << " " << y << endl;


    return 0;
}
// -1 -2 -3
// 