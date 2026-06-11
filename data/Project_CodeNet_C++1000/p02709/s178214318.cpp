/*
          ,     \    /      ,
         / \    )\__/(     / \
        /   \  (_\  /_)   /   \
   ____/_____\__\@  @/___/_____\____
  |             |\../|              |
  |              \VV/               |
  |        ------hoi-------         |
  |_________________________________|
   |    /\ /      \\       \ /\    |
   |  /   V        ))       V   \  |
   |/     `       //        '     \|
   `              V                '
*/

#include <bits/stdc++.h>

#define ld long double
#define ll long long
#define ull unsigned long long
#define pb push_back
#define mp make_pair
#define f first
#define se second
#define Speedforce boost();
#define fop(s1, s2) freopen(s1, "r", stdin);freopen(s2, "w", stdout);

using namespace std;

void boost(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

const int N = 1e6;
const ll inf = 1e9 + 7;
const ld PI = acos(-1);

ll bin_pow(ll x, ll y){
    ll res = 1, base = x;
    while(y){
        if(y & 1){
            res *= base;
            res %= inf;
        }
        base *= base;
        base %= inf;
        y /= 2;
    }
    return res;
}

int n;
ll dp[2005][2005];
pair <ll, ll> a[2005];
bool was[2005][2005];

ll rec(int l, int r){
    if(l > r){
        return 0;
    }
    if(was[l][r]){
        return dp[l][r];
    }
    was[l][r] = 1;
    ll v = a[r - l + 1].f, pos = a[r - l + 1].se;
    return dp[l][r] = max(rec(l + 1, r) + v * abs(pos - l), rec(l, r - 1) + v * abs(pos - r));
}

int main(){
    Speedforce
    //fop("F.in", "F.out")
    //mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());
    cin >> n;
    for(int i = 1;i <= n;i ++){
        cin >> a[i].f;
        a[i].se = i;
    }
    sort(a + 1, a + 1 + n);
    cout << rec(1, n);
}
