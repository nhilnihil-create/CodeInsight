#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <cstdint>
#include <cstdio>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cctype>
#define ll long long int
#define pb push_back
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)
using namespace std;

int mx8[] = {0,0,1,-1,-1,1,-1,1};
int my8[] = {-1,1,0,0,-1,-1,1,1};
int mx4[] = {1,-1,0,0};
int my4[] = {0,0,-1,1};

ll MOD = 998244353;


int main() {
    int n; cin >> n;
    vector<ll> d(n);
    rep(i,n) cin >> d[i];
    if(d[0] != 0) {cout << 0 << endl; return 0;}
    sort(d.begin(),d.end());

    ll MAX = d[n-1];
    ll ko[MAX+1];
    rep(i,MAX+1) ko[i] = 0;
    rep(i,n) ko[d[i]]++;
    if(ko[0] != 1){cout << 0 << endl; return 0;}

    ll ans = 1; //rep(i,MAX+1) cout << ko[i] << endl;
    rep(i,MAX+1){if(ko[i] == 0){cout << 0 << endl; return 0;}}

    rep(i,MAX){
        rep(j,ko[i+1]){
            ans *= (ko[i] % MOD);
            ans %= MOD;
        }
    }
    cout << ans % MOD << endl;

}
