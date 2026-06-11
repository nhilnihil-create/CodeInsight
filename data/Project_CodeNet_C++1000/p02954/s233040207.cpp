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
        auto v = runlength(S);
        vll ans;
        rep(i, 0, len(v)) {
                ll l = v[i].second;
                ll r = v[i+1].second;
                ll cnt1 = 0, cnt2 = 0;
                if ((l + r) % 2 == 0) {
                        cnt1 = cnt2 = (l + r) / 2;
                } else {
                        cnt1 = cnt2 = (l + r) / 2;
                        ll tmp = max(l, r);
                        if (odd(tmp)) {
                                if (l > r) ++cnt1;
                                else ++cnt2;
                        } else {
                                if (l > r) ++cnt2;
                                else ++cnt1;
                        }
                }

                rep(j, 0, l-1) {
                        ans.push_back(0);
                }
                ans.push_back(cnt1);
                ans.push_back(cnt2);
                rep(j, 0, r-1) {
                        ans.push_back(0);
                }
                ++i;
        }

        rep(i, 0, len(ans)) {
                if (i != len(ans) - 1) cout << ans[i] << ' ';
                else cout << ans[i] << endl;
        }
}