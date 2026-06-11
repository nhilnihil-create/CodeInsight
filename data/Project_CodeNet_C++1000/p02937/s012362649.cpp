#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;
using PLL = pair<ll, ll>;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repn(i,n) for(int i = 0; i <= (int)(n); i++)
#define srep(i,l,n) for(int i = l; i < (int)(n); i++)
#define srepn(i,l,n) for(int i = l; i <= (int)(n); i++)
#define drep(i,n) for(int i = (int)(n-1); i >= 0; i--)
#define drepn(i,n) for(int i = (int)(n); i >= 0; i--)
#define size(s) (int)s.size()
#define debug(var)  do{std::cout << #var << " : ";view(var);}while(0)
template<typename T> void view(T e){std::cout << e << std::endl;}
template<typename T> void view(const std::vector<T>& v){for(const auto& e : v){ std::cout << e << " "; } std::cout << std::endl;}
template<typename T> void view(const std::vector<std::vector<T> >& vv){ for(const auto& v : vv){ view(v); } }
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
template<class T = int> using V = vector<T>;
template<class T = int> using VV = vector<V<T>>;
bool isIn(int i, int j, int h, int w) {return i >= 0 && i < h && j >= 0 && j < w;}
void Yes(){cout << "Yes" << endl;}
void No(){cout << "No" << endl;}
void YES(){cout << "YES" << endl;}
void NO(){cout << "NO" << endl;}
void err() {cout << -1 << endl;}
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define ep emplace_back

const int MOD = 1000000007;
const int INF = 1e9;

#define PI acos(-1);
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int ddx[8] = {1,1,1,-1,-1,-1,0,0};
int ddy[8] = {0,1,-1,0,1,-1,1,-1};


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s, t;
    cin >> s >> t;
    VV<ll> c(26);
    rep(i, size(s)) {
        int now = s[i] - 'a';
        c[now].push_back(i);
    }
    ll ans = 0;
    int pos = -1;
    rep(i, size(t)) {
        int now = t[i] - 'a';
        if(c[now].empty()) {
            cout << -1 << endl;
            return 0;
        }
        auto it = upper_bound(all(c[now]), pos);
        if(it == c[now].end()) {
            ans = (ans+(ll)size(s)-1)/(ll)size(s)*(ll)size(s)+c[now][0]+1;
            pos = c[now][0];
        }else {
            ans = ans/(ll)size(s)*(ll)size(s)+*it+1;
            pos = *it;
        }
    }
    cout << ans << endl;
}