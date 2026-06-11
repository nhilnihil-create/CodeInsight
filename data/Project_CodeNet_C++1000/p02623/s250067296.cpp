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

    ll n, m, k;
    cin >> n >> m >> k;

    vector<ll> arr(n);
    vector<ll> brr(m);

    ll sum = 0, best = 0, curr;

    bool got = true;

    for(int i = 0; i < n; i++){
        cin >> arr[i];

        if(i) arr[i] += arr[i - 1];

        if(arr[i] > k && got) best = i, got = false;
        else if(arr[i] == k) best = i + 1;
    }

    for(int i = 0; i < m; i++){
        cin >> brr[i];

        sum += brr[i];

        if(sum > k) break;

        auto it = ub(all(arr), k - sum);

        curr = it - arr.begin();

        best = max(best, curr + i + 1);
    }

    cout << best;
}
