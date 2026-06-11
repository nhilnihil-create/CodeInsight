#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int (i)=0;i<(n);i++)
#define REP(i,m,n) for(int (i)=(m);(i)<(n);(i)++)
#define INF INT_MAX
#define MOD 1000000007
#define fcout cout << fixed << setprecision(15)
#define int long long
#define yorn(f) puts((f)?"Yes":"No")
#define YORN(f) puts((f)?"YES":"NO")
#define sec second
#define fir first
typedef long long ll;
typedef pair<int, int> P;
typedef priority_queue<int> pque;
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
    
    int n, d, a;
    cin >> n >> d >> a;
    vector<vector<int>> v(n, vector<int>(2)); // v[i][0]:場所, v[i][1]:体力
    rep(i, n) cin >> v[i][0] >> v[i][1];
    sort(all(v));

    vector<vector<int>> query;
    int nextQuery = 0;
    int nowDamage = 0;
    int ret = 0;
    rep(i, n) {
        while(query.size() > nextQuery && query[nextQuery][0] < v[i][0]) {
            nowDamage -= query[nextQuery][1];
            nextQuery++;
        }

        if(nowDamage < v[i][1]) {
            int count = mod(v[i][1] - nowDamage, a);
            query.push_back({v[i][0] + d * 2, a * count});
            nowDamage += a * count, ret += count;
        }
    }

    cout << ret << endl;
    
    return 0;
}