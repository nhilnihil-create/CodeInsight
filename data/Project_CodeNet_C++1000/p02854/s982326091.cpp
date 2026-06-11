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
#include <random>
#include <cassert>
#include <numeric>
#define ll long long int
#define LL unsigned long long
#define pb push_back
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)
using namespace std;

int mx8[] = {0,0,1,-1,-1,1,-1,1};
int my8[] = {-1,1,0,0,-1,-1,1,1};
int mx4[] = {1,-1,0,0};
int my4[] = {0,0,-1,1};
const int MOD = 1000000007;



int main() {
    int n; cin >> n;
    vector<ll> a(n),r(n),l(n);
    rep(i,n) {
        cin >> a[i];
        r[i] = a[i];
        l[i] = a[i];
    }

    rep(i,n-1) l[i+1] += l[i];
    for(int i = n - 2; i >= 0; i--) r[i] += r[i+1];

    ll v = 20202020200;
    for(int i = 0; i < n - 1; i++){
        v = min(v,abs(l[i]-r[i+1]));
    }
    /*for(ll i : r) cout << i << " ";
    cout << endl;
    for(ll i : l ) cout << i << " ";
    cout << endl;*/
    cout << v << endl;
}