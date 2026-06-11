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

typedef pair<int, int> P;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, K;
    cin >> N >> K;
    int upper = (N - 1) * (N - 2) / 2;
    if(upper < K) {
        cout << -1 << endl;
        return 0;
    }
    vector<P> A;
    rep(i, N - 1) {
        A.push_back({0, i + 1});
    }
    int add = upper - K;
    int left = 1, right = 2;
    while(add--) {
        A.push_back({left, right});
        right++;
        if(right == N) {
            left++;
            right = left + 1;
        }
    }
    cout << A.size() << endl;
    for(auto& e: A) {
        cout << e.first + 1 << " " << e.second + 1 << endl;
    }

    return 0;
}
