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
#include <numeric>
#define ll long long int
#define pb push_back
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)
using namespace std;

int mx8[] = {0,0,1,-1,-1,1,-1,1};
int my8[] = {-1,1,0,0,-1,-1,1,1};
int mx4[] = {1,-1,0,0};
int my4[] = {0,0,-1,1};
const int MOD = 1000000007;

ll y[10000005];

int main() {
    int n;
    cin >> n;
    vector<ll> a(n),kai,uri;
    rep(i,n) cin >> a[i];

    for(int i = 0; i < n-1; i++){
        if(a[i] < a[i+1]) {
            kai.pb(a[i]);
            uri.pb(a[i+1]);
        }
    }
    //for(int i:kai) cout << i << endl;
    ll N = uri.size(),money = 1000, kabu = 0;
    rep(i,N){
        kabu += money / kai[i];
        money %= kai[i];
        money += uri[i] * kabu;
        kabu = 0;
    }
    cout << money << endl;
}