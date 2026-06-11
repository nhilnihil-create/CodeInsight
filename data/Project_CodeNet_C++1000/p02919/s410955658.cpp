#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll, ll> Pll;
#define debug(var)  do{std::cout << #var << " : ";view(var);}while(0)
template<typename T> void view(T e){std::cout << e << std::endl;}
template<typename T> void view(const std::vector<T>& v){for(const auto& e : v){ std::cout << e << " "; } std::cout << std::endl;}
template<typename T> void view(const std::vector<std::vector<T> >& vv){ for(const auto& v : vv){ view(v); } }
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const int MOD = 1000000007;
const int INF = 1e9;

const int mod = 1000000007;
const int inf = 1e9;
#define PI acos(-1);
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int ddx[8] = {1,1,1,-1,-1,-1,0,0};
int ddy[8] = {0,1,-1,0,1,-1,1,-1};


int main(){
    int n;
    cin >> n;
    vector<int> a(n), pos(n);
    ll ans = 0;
    for(int i = 0; i < n; i++) cin >> a[i], a[i]--, pos[a[i]] = i;
    set<int> s;
    for(int i = n-1; i >= 0; i--) {
        int x = pos[i];
        s.insert(x);
        ll c = 0;
        vector<int> l(2, -1), r(2, n);
        {
            int f = 0;
            auto it = s.find(x);
            while(it!=s.begin()) {
                it--;
                l[f] = *it;
                f++;
                if(f == 2) break;
            }
        }
        {
            int f = 0;
            auto it = s.find(x);
            while(1) {
                it++;
                if(it == s.end()) break;
                r[f] = *it;
                f++;
                if(f == 2) break;
            }
        }

        vector<int> ls(2), rs(2);
        ls[0] = x - l[0];
        ls[1] = l[0] - l[1];
        rs[0] = r[0] - x;
        rs[1] = r[1] - r[0];
        c = (ll)rs[1]*ls[0]+(ll)rs[0]*ls[1];
        ans += c*(i+1);
    }

    cout << ans << endl;

}