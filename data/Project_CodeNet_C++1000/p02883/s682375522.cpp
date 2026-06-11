#include <algorithm>
#include <bitset>
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
#include <list>
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
/*
 def get_target(l, h, n, fs)
 r = 0
 fs.each do |f| r += h / f end
 
 # t0 = (l*h/r).ceil, t = (l*h/(r+n)).ceil
 lh = l * h
 t0 = (lh + r - 1) / r
 t = (lh + r + n - 1) / (r + n)
 
 raise if (t0 >= t + 2)
 
 t
 end
 */
ll get_tangent(ll l, __int128 h, ll n, vector<ll>& fs){
    __int128 r = 0;
    for(auto f : fs){
        r += h / f;
    }
    __int128 lh = (__int128)l * h;
    ll t0 = (lh + r - 1) / r;
    ll t = (lh + r + n - 1) / (r + n);
    return t;
}
int main(){
    /*
     n, k = gets.split.map(&:to_i)
     as = gets.split.map(&:to_i)
     fs = gets.split.map(&:to_i)
     
     l = as.inject(:+) - k
     
     if (l <= 0)
     p 0
     exit
     end
     */
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    ll k;
    cin >> k;
    vector<ll> as(n), fs(n);
    for(int i = 0; i < n; i++){
        cin >> as[i];
    }
    for(int i = 0; i < n; i++){
        cin >> fs[i];
    }
    ll l = accumulate(as.begin(), as.end(), 0LL) - k;
    if(l <= 0){
        cout << 0 << endl;
        return 0;
    }
    /*
     # O(n * log(n))
     afs = as.sort.zip(fs.sort.reverse).sort_by do |item| item[0]*item[1] end
     */
    using P = pair<ll, ll>;
    vector<P> afs(n);
    sort(as.begin(), as.end());
    sort(fs.rbegin(), fs.rend());
    for(int i = 0; i < n; i++){
        afs[i] = make_pair(as[i], fs[i]);
    }
    sort(afs.begin(), afs.end(), [&](P &x, P &y){
        return x.first * x.second < y.first * y.second;
    });
    /*
     # O(n * log(n))
     m = (0...n).bsearch do |i|
       a_i, f_i = afs[i]
       af = a_i * f_i
      
       s = 0
       afs.each do |a,f| s += [af / f, a].min end
       s > l
     end
     */

    auto check = [&](int i) -> bool{
        ll a_i = afs[i].first;
        ll f_i = afs[i].second;
        ll af = a_i * f_i;
        ll s = 0;
        for(auto &x : afs){
            ll a = x.first;
            ll f = x.second;
            s += min(af / f, a);
        }
        return s > l;
    };
    int L = -1, R = n - 1;
    while(R - L > 1){
        int mid = (L + R) / 2;
        if(check(mid))R = mid;
        else L = mid;
    }
    int m = R;
    
    /*
     if (m > 0)
       afs = afs.drop(m)
       n -= m
     end
     */
    if(m > 0){
        afs = vector<P> (afs.begin()+m, afs.end());
        n -= m;
    }
    /*
     l = -k
     max_f = 0
      
     # O(n)
     fs = afs.map do |a, f|
       l += a
       max_f = f if f > max_f
       f
     end
      
     # O(n)
     t = get_target(l, l * max_f * max_f, n, fs)
      
     max_af = 0
     */
    l = - k;
    ll max_f = 0;
    fs.resize(n);
    for(int i = 0; i < n; i++){
        ll a = afs[i].first;
        ll f = afs[i].second;
        l += a;
        max_f = max(max_f, f);
        fs[i] = f;
    }
    ll t = get_tangent(l, (__int128)l * max_f * max_f, n, fs);
    ll max_af = 0;
    /*
     # O(n)
     xs = fs.map do |f|
       l -= (a = t / f)
       af = a * f
       max_af = af if af > max_af
       [af + f, f]
     end
     */
    vector<P> xs(n);
    for(int i = 0; i < n; i++){
        ll f = fs[i];
        ll a;
        l -= (a = t / f);
        ll af = a * f;
        max_af = max(max_af, af);
        xs[i] = make_pair(af + f, f);
    }
    
    /*
     if (l == 0)
       p max_af
     else
       # O(n * log(n))
       q = Heap.new(xs) do |a,b| a.first < b.first end
      
       # assert: l <= 2*n
       # O(n * log(n))
       af, = q.replace do |a| [a[0] + a[1], a[1]] end while (l -= 1) >= 0
       p af
     end
     */
    if(l == 0){
        cout << max_af << endl;
    }else{
        priority_queue<P, vector<P>, greater<P>> pq;
        for(auto &x : xs)pq.push(x);
        ll af;
        do{
            auto a = pq.top();
            pq.pop();
            af = a.first;
            pq.emplace(a.first + a.second, a.second);
        }while(l -= 1 >= 0);
        cout << af << endl;
    }
}
