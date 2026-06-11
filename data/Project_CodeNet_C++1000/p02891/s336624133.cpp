#include <bits/stdc++.h>
#define rep(i, start, end) for (long long i = start; i < end; ++i)
#define repreverse(i, start, end) for (long long i = start; i >= end; --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define len(x) ((long long)(x).size())
#define lcm(a, b) ((a) / __gcd((a), (b)) * (b))
using namespace std;
using ll = long long;
using ld = long double;
using vll = vector<ll>;
using vllvll = vector<vll>;
using pll = pair<ll, ll>;
template<class T>void print1d(T x,ll n=-1){if(n==-1)n=x.size();rep(i,0,n){cout<<x[i]<<' ';}cout<<'\n';}
template<class T>void print2d(T x,ll r=-1,ll c=-1){if(r==-1)r=x.size();if(c==-1)c=x[0].size();rep(i,0,r)print1d(x[i],c);}
template<class T, class U>bool haskey(T mp, U key) { return mp.find(key) != mp.end(); }
template<class T, class U>bool isin(T el, U container) { return find(all(container), el) != container.end(); }
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }
template<class T>bool even(T n) { return ! (n & 1); }
template<class T>bool odd(T n) { return n & 1; }
template<class T>ld deg2rad(T deg) { return M_PI * deg / 180.0; }
template<class T>ld rad2deg(T rad) { return 180.0 * rad / M_PI; }
ll intpow(ll a,ll n){ll p=1;while(n){if(n&1)p*=a;a*=a;n>>=1;}return p;} 
const long double pi = M_PI;
const long long big = 1LL << 50;
const long long inf = 1LL << 60;
const long long mod = 1e9 + 7;

std::vector<std::pair<char, long long> > runlength(std::string str)
{
        std::vector<std::pair<char, long long> > enc;
        long long strsize = static_cast<long long>(str.size());

        char now = str[0];
        long long cnt = 0;
        for (long long i = 0; i < strsize; ++i) {
                if (str[i] == now) {
                        ++cnt;
                } else {
                        enc.push_back(std::pair<char, long long>(now, cnt));
                        now = str[i];
                        cnt = 1;
                }
        }
        enc.push_back(std::pair<char, long long>(now, cnt));
        return enc;
}


int main()
{
        string S;
        cin >> S;
        ll K;
        cin >> K;
        auto v = runlength(S);
        if (len(v) == 1) {
                cout << len(S) * K / 2 << endl;
                return 0;
        }
        ll ans = 0;

        ll tmp = 0;
        rep(i, 0, len(v)) {
                tmp += v[i].second / 2;
        }

        ans += tmp * K;

        if (v.front().first == v.back().first) {
                ll tmp = v.front().second/2 + v.back().second/2 - (v.front().second + v.back().second) / 2;
                ans -= tmp * (K-1);
        }

        cout << ans << endl;


        // rep(i, 1, len(v)-1) {
        //         ans += v[i].second / 2;
        // }
        // ans *= K;

        // ll tmp = 0;
        // if (v.front().first == v.back().first) tmp = (v.front().second + v.back().second) / 2;

        // ans += tmp * (K-1);

        // ans += v.front().second / 2; 
        // ans += v.back().second / 2;

        // cout << ans << endl;

        // for (auto x : v) {
        //         cout << x.first << ' ' << x.second << endl;
        // }

        // string T;
        // rep(i, 0, K) {
        //         T += S; 
        // }

        // ll debug = 0;
        // rep(i, 0, len(T)-1) {
        //         if (T[i] == T[i+1]) ++debug;
        //         ++i;
        // }
        // if (T[len(T)-2] == T.back()) ++debug;
        // cout << debug << endl;
}
