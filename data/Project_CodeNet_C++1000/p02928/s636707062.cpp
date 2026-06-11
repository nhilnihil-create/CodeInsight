#include<iostream>
#include<unordered_map>
#include<bitset>
#include<math.h>
#include<vector>
#include<set>
#include<algorithm>
#include<ctype.h>
#include<unordered_set>
#include<string>
#include<iomanip>
#include<queue>
#include<limits>
#include<map>
#include<stack>
#include<iterator>
#include<cstring>
#include<deque>
#include<chrono>
using namespace std;
#define pi 3.141592653589793238


#define MOD 1000000007
#define INF 999999999999999999 
#define pb push_back
#define ff first
#define ss second
#define mt make_tuple
#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define f0 get<0>
#define f1 get<1>
#define f2 get<2>
typedef vector<ll> vi;
typedef vector<vi> vvi;


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fast;
    ll T = 1, i, j;
    
    
    //cin >> T;
    while (T--) {
        ll n, k;
        cin >> n >> k;
        vector<ll> v(n);
        for(i =0 ;i < n; i++){
            cin >> v[i];
        }
        vector<ll> bef(n), aft(n);
        for(i = 0; i < n; i++){
            for(j = 0; j < i; j++){
                if(v[j] < v[i]){
                    bef[i]++;
                }
            }
            for(j = i + 1; j < n; j++){
                if(v[j] < v[i]){
                    aft[i]++;
                }
            }
        }
        ll ans = 0;
        for(i = 0; i <n ;i++){
            ll b, a;
            b = bef[i], a = aft[i];
            ans += k * a + (a + b) * ((k * k - (k * (k + 1) / 2)) % MOD);
            ans %= MOD;
        }
        cout << ans;
    }

    return 0;
}
