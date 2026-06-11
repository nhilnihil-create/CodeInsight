//Bismillahir Rahmanir Rahim
#include <bits/stdc++.h>
using namespace std;

typedef long long              ll;
typedef long double            ld;
typedef pair<int, int>         pi;
typedef vector<int>            vi;
typedef vector<pair<int, int>> vpi;

#define pb       push_back
#define all(x)   begin(x), end(x)
#define sz(x)    (int)(x).size()
#define ff       first
#define ss       second
#define mp       make_pair
#define lb       lower_bound
#define ub       upper_bound
#define tcase()  int t; cin >> t; while(t--)

const int MOD = 1e9 + 7; // 998244353;
const int MX  = 2e5 + 5;
const ll  INF = 1e18;
const ld  PI  = acos((ld) -1);

void setIO(string name = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(sz(name)){
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}

int main(){

    setIO();

    int n;
    cin >> n;

    vi pls;
    vi mns;

    int Ans = 0;

    for(int i = 0; i < n; i++){

        int a, b;
        cin >> a >> b;

        pls.pb(a + b);
        mns.pb(a - b);
    }

    sort(all(pls));
    sort(all(mns));

    cout << max(pls[n - 1] - pls[0], mns[n - 1] - mns[0]);
}
