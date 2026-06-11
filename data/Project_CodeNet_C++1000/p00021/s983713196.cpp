#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

#define rep(i, n) for(int i = 0; i < n; i ++)
#define ALL(T) T.begin(), T.end()
#define mp make_pair
#define pb push_back
#define X first
#define Y second

using namespace std;

typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<string> vs;

const int INF = 1 << 24;

int main(void){
    int n; cin >> n;

    while(n --){
        vector<pair<double, double> > in(4);
        vector<double> m(2);

        rep(i, 4) cin >> in[i].X >> in[i].Y;
        rep(i, 2) m[i] = (in[2 * i].Y - in[2 * i + 1].Y) / (in[2 * i].X - in[2 * i + 1].X);
        if(m[0] == m[1]) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}