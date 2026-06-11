#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int (i)=0;i<(n);i++)
#define REP(i,m,n) for(int (i)=(m);(i)<(n);(i)++)
#define MOD 1000000007
#define fcout cout << fixed << setprecision(15)
#define int long long
#define yorn(f) puts((f)?"Yes":"No")
#define YORN(f) puts((f)?"YES":"NO")
typedef long long ll;
typedef pair<int, int> P;
int gcd(int a,int b){return b?gcd(b,a%b):a;};
int lcm(int a,int b){return a/gcd(a,b)*b;};
int mod(int a,int b){return (a+b-1)/b;};
template<typename A, size_t N, typename T>
void Fill(A(&array)[N],const T &val){std::fill((T*)array,(T*)(array+N),val);}
template<class T>inline bool chmax(T& a,T b){if(a<b){a=b;return true;}return false;};
template<class T>inline bool chmin(T& a,T b){if(a>b){a=b;return true;}return false;};



signed main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    
    int n, k;
    cin >> n >> k;
    map<int, vector<int>> mp;
    int cursum = 0;
    mp[cursum] = vector<int>{0};
    vector<int> sum(n + 1);

    for(int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        cursum += a - 1;
        cursum %= k;
        if(mp.find(cursum) == mp.end()) {
            mp[cursum] = vector<int>();
        }
        mp[cursum].push_back(i);
        sum[i] = sum[i - 1] + cursum;
    }

    int ans = 0;
    for(auto curv : mp) {
        for(auto x : curv.second) {
            ans += lower_bound(all(curv.second), x + k) - upper_bound(all(curv.second), x);
        }
    }
    cout << ans << endl;
    return 0;
}