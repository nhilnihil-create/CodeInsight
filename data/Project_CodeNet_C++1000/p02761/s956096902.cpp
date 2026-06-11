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

set<int> st[3];
int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    rep(i, M) {
        int s, c;
        cin >> s >> c;
        s--;
        st[s].insert(c);
    }
    rep(i, N) {
        if(st[i].size() > 1) {
            cout << -1 << endl;
            return 0;
        }
    }
    string A = "";
    rep(i, N) {
        int num = 0;
        if(st[i].size() == 1) {
            num = *st[i].begin();
            if(i == 0 && N != 1 && num == 0) {
                cout << -1 << endl;
                return 0;
            }
        }
        if(i == 0 && N != 1 && num == 0) num = 1;
        //cout << num;
        A += to_string(num);
    }
    cout << A << endl;

    return 0;
}
