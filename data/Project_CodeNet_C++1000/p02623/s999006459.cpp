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
#include <cmath>
#include <iomanip> //cout << fixed << setprecision(15) << << endl;
#include <cassert>


using namespace std;


#define ll long long int
#define pb push_back
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)
#define P pair<int,int>

int mx8[] = {0,0,1,-1,-1,1,-1,1};
int my8[] = {-1,1,0,0,-1,-1,1,1};
int mx4[] = {1,-1,0,0};
int my4[] = {0,0,-1,1};
const int MOD = 1000000007;


int main(){
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
    int n, m; ll k;
    cin >> n >> m >> k;
    vector<ll> a(n), b(m),A(n+1);
    rep(i,n) cin >> a[i];
    rep(i,m) cin >> b[i];
    rep(i,n-1) a[i+1] += a[i];
    rep(i,m-1) b[i+1] += b[i];
    a.insert(a.begin(),0);

    int ans = 0;
    for(int i = 0; i < n+1; ++i){
        if(k-a[i] < 0) break;

        auto itr = lower_bound(b.begin(),b.end(), k-a[i]);
        int cnt = distance(b.begin(),itr);
        if(*itr == k-a[i]) cnt++;
        ans = max(ans, cnt + i);
    }

    cout << ans << endl;
}

