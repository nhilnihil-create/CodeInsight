#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<int>;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
constexpr int INF = 0x3f3f3f3f; constexpr ll LLINF = 0x3f3f3f3f3f3f3f3f;
#define db(x) { cerr << #x << " = " << x << endl; }
template <typename T> void _dbarr(T* a, size_t sz){ for(int i = 0; i < sz; i++) cerr << a[i] << " \n"[i == sz-1]; }
template <typename T> void _dbarr(vector<T> a, size_t sz){ for(int i = 0; i < sz; i++) cerr << a[i] << " \n"[i == sz-1]; }
#define dbarr(x, n) {cerr << #x << ": "; _dbarr((x),(n));}
#define all(x) begin(x), end(x)
#define pb push_back
#define eb emplace_back
#define mpr make_pair
#define fs first
#define sn second
const int MM = 7;
int h,w,k;
char grid[MM][MM],cur[MM][MM];
int main() {
	//cin.tie(0)->sync_with_stdio(0);
    cin >> h >> w >> k;
    int cnt = 0;
    for(int i = 0; i < h; i++) for(int j = 0; j < w; j++)
        cin >> grid[i][j],cnt += (grid[i][j] == '#');
    int ans = 0;
    for(int maskr = 0; maskr < (1<<h); maskr++){
        for(int maskc = 0; maskc < (1<<w); maskc++){
            int cur = 0;
            for(int i = 0; i < h; i++){
                for(int j = 0; j < w; j++){
                    if(!(maskr & (1<<i)) && !(maskc & (1<<j))){
                        cur += (grid[i][j] == '#');
                    }
                }
            }
            ans += (cur==k);
        }
    }
    cout << ans << "\n";
}
