#include <algorithm>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <vector>
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
//#define cerr if(false) cerr
#ifdef DEBUG
#define show(...) cerr << #__VA_ARGS__ << " = ", debug(__VA_ARGS__);
#else
#define show(...) 42
#endif
using namespace std;
using ll = long long;
using pii = pair<int, int>;
template <typename T, typename S>
ostream& operator<<(ostream& os, pair<T, S> a) {
    os << '(' << a.first << ',' << a.second << ')';
    return os;
}
template <typename T>
ostream& operator<<(ostream& os, vector<T> v) {
    for (auto x : v) os << x << ' ';
    return os;
}
void debug() {
    cerr << '\n';
}
template <typename H, typename... T>
void debug(H a, T... b) {
    cerr << a;
    if (sizeof...(b)) cerr << ", ";
    debug(b...);
}
typedef long long int           ll;
typedef unsigned long long int  ull;

ull check_bit(ull N,int POS){return (N & (1ULL<<POS));}

vector<ull>v;
ull gaussian_elimination()
{
    int n=v.size();
    int ind=0;  // Array index
    for(int bit=log2(v[0]);bit>=0;bit--)
    {
        int x=ind;
        while(x<n&&check_bit(v[x],bit)==0)
            x++;
        if(x==n)
            continue; // skip if there is no number below ind where current bit is 1
        swap(v[ind],v[x]);
        for(int j=0;j<n;j++)
        {
            if(j!=ind&&check_bit(v[j],bit))
                v[j]^=v[ind];
        }
        ind++;
    }
    ull ans=v[0];
    for(int i=1;i<n;i++)
        ans=max(ans,ans^v[i]);
    return ans;
}
int main(){
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n)cin >> a[i];
    vector<int>cnt(61);
    rep(i,n){
        show((bitset<7>(a[i])));
        rep(j,61){
            if(a[i] >> j & 1)cnt[j]++;
        }
    }
    show(cnt);
    ll ans = 0;
    rep(j,61)if(cnt[j]&1){
        ans += 1LL << j;
        cnt[j] = 0;
        rep(i,n)if(a[i] >> j & 1){
            a[i] ^= 1LL<<j;
        }
    }
    rep(i,n)v.push_back(a[i]);
    sort(v.rbegin(),v.rend());
    cout << ans + gaussian_elimination() * 2 << endl;
}
