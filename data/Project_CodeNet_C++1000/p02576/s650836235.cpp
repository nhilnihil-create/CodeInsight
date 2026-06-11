#include<bits/stdc++.h>

using namespace std;


typedef unsigned long long ull;
typedef long long ll;
typedef unsigned int ui;
typedef vector<int> vi;
typedef vector<double> vd;
typedef pair<int,int> pii;
typedef vector<ull> vull;

#define pb push_back;
#define FOR(i,a,b) for(int i = a; i <=b; ++i)
#define FORDOWN(i,a,b) for(int i = a; i >= b; --i)
#define F first;
#define S second;
#define rnd() mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("sparse.in", "r", stdin);
    // freopen("sparse.out", "w", stdout);

    int n,x,t;
    cin >> n >> x >> t;

    int ans = 0;

    while(n > x) {
        ans += t;
        n -= x;
    }

    cout << ans + t;


     return 0;
}