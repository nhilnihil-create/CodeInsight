#include <bits/stdc++.h>
#define rep(i, start, end) for (long long i = start; i < end; ++i)
#define srt(x) sort((x).begin(), (x).end());
#define rsrt(x) sort((x).rbegin(), (x).rend());
#define deb(x) cout<<#x<<" = "<<(x)<<" (L"<<LINE<<")"<<endl;
#define vdeb(x) {cout<<#x<<" = { "; rep(i, x.size()) cout<<x[i]<<' '; cout <<'}'<<" (L"<<LINE<<")"<<endl;}
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<int>;
using vivi = vector<vi>;
using vll = vector<long long>;
using vllvll = vector<vll>;
using vs = vector<string>;
using um = unordered_map<long long, long long>;
const long long INF = 1LL << 60;
const long long MOD = 1e9 + 7;

int main()
{
    ll M;
    cin >> M;
    vll d(M), c(M);
    rep(i, 0, M) {
        cin >> d[i] >> c[i];
    }
    ll tmp = accumulate(c.begin(), c.end(), 0LL);
    ll sm = 0;
    rep(i, 0, M) {
        sm += d[i] * c[i];
    }
//    sm = (sm-1) / 9;
    cout << tmp + (sm-1)/9 - 1 << endl;

}