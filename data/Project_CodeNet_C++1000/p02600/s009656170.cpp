#include <bits/stdc++.h>
 
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp> 
// using namespace __gnu_pbds; 
  
// #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
 
const int MOD = 1e9+7;
// const int MOD  = 998244353;
const int INF = 0x3f3f3f3f;
const double PI = 4*atan(1);
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
// struct custom_hash {
//     static uint64_t splitmix64(uint64_t x) {
//         // http://xorshift.di.unimi.it/splitmix64.c
//         x += 0x9e3779b97f4a7c15;
//         x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
//         x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
//         return x ^ (x >> 31);
//     }
 
//     size_t operator()(uint64_t x) const {
//         static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
//         return splitmix64(x + FIXED_RANDOM);
//     }
// };
// ll gcd(ll a, ll b) { 
//     if (a == 0) return b; 
//     return gcd(b % a, a); 
// }
// ll mod(ll x) {
//     x%=MOD;
//     if(x<0)x+=MOD;
//     return x;
// }
// ll power(int base, int power) {
//     ll prod = 1;
//     ll b = base;
//     while(power) {
//         if (power & 1) {
//             prod = mod(prod*b);
//         }
//         b = mod(b*b);
//         power/=2;
//     }
//     return prod;
// }
// struct line {
//     ll m, c;
//     ll eval(int x) { return 1LL * m * x + c; }
//     double intersect(line l) { return (double) (c - l.c) / (l.m - m); }
// };
// double degToRad(double x) {
//  return x * PI / 180;
// }
// double area(int a, int b, int c, int d, int e, int f) {
//  return abs(0.5*(a*(d-f)+c*(f-b)+e*(b-d)));
// }
// struct str {
//     string s;
//     ll h[100005];
//     ll p[100005];
//     ll base=37;
//     void hsh(){
//         h[0] = s[0]-'a';
//         p[0] = 1;
//         for(int i=1;i<s.length();i++){
//             h[i]=h[i-1]*base+s[i]-'a';
//             p[i]=p[i-1]*base;
//         }
//     }
//     ll getHash(int l,int r){
//         if(l==0) return h[r];
//         return h[r]-h[l-1]*p[r-l+1];
//     }
// };
 
// line sweep template https://cp-algorithms.com/geometry/intersecting_segments.html
// const ld EPS = 1E-12;
 
// struct pt {
//     ld x, y;
// };
 
// struct seg {
//     pt p, q;
//     int id;
 
//     ld get_y(double x) const {
//         if (abs(p.x - q.x) < EPS)
//             return p.y;
//         return p.y + (q.y - p.y) * (x - p.x) / (q.x - p.x);
//     }
// };
 
// bool intersect1d(ld l1, ld r1, ld l2, ld r2) {
//     if (l1 > r1)
//         swap(l1, r1);
//     if (l2 > r2)
//         swap(l2, r2);
//     return max(l1, l2) <= min(r1, r2) + EPS;
// }
 
// int vec(const pt& a, const pt& b, const pt& c) {
//     double s = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
//     return abs(s) < EPS ? 0 : s > 0 ? +1 : -1;
// }
 
// bool intersect(const seg& a, const seg& b)
// {
//     return intersect1d(a.p.x, a.q.x, b.p.x, b.q.x) &&
//            intersect1d(a.p.y, a.q.y, b.p.y, b.q.y) &&
//            vec(a.p, a.q, b.p) * vec(a.p, a.q, b.q) <= 0 &&
//            vec(b.p, b.q, a.p) * vec(b.p, b.q, a.q) <= 0;
// }
 
// bool operator<(const seg& a, const seg& b)
// {
//     ld x = max(min(a.p.x, a.q.x), min(b.p.x, b.q.x));
//     return a.get_y(x) < b.get_y(x) - EPS;
// }
 
// struct event {
//     ld x;
//     int tp, id;
 
//     event() {}
//     event(ld x, int tp, int id) : x(x), tp(tp), id(id) {}
 
//     bool operator<(const event& e) const {
//         if (abs(x - e.x) > EPS)
//             return x < e.x;
//         return tp > e.tp;
//     }
// };
 
// set<seg> s;
// vector<set<seg>::iterator> where;
 
// set<seg>::iterator prev(set<seg>::iterator it) {
//     return it == s.begin() ? s.end() : --it;
// }
 
// set<seg>::iterator next(set<seg>::iterator it) {
//     return ++it;
// }
 
// pair<int, int> solve(const vector<seg>& a) {
//     int n = (int)a.size();
//     vector<event> e;
//     for (int i = 0; i < n; ++i) {
//         e.push_back(event(min(a[i].p.x, a[i].q.x), +1, i));
//         e.push_back(event(max(a[i].p.x, a[i].q.x), -1, i));
//     }
//     sort(e.begin(), e.end());
 
//     s.clear();
//     where.resize(a.size());
//     for (size_t i = 0; i < e.size(); ++i) {
//         int id = e[i].id;
//         if (e[i].tp == +1) {
//             set<seg>::iterator nxt = s.lower_bound(a[id]), prv = prev(nxt);
//             if (nxt != s.end() && intersect(*nxt, a[id]))
//                 return make_pair(nxt->id, id);
//             if (prv != s.end() && intersect(*prv, a[id]))
//                 return make_pair(prv->id, id);
//             where[id] = s.insert(nxt, a[id]);
//         } else {
//             set<seg>::iterator nxt = next(where[id]), prv = prev(where[id]);
//             if (nxt != s.end() && prv != s.end() && intersect(*nxt, *prv))
//                 return make_pair(prv->id, nxt->id);
//             s.erase(where[id]);
//         }
//     }
 
//     return make_pair(-1, -1);
// }
// const int maxn = 400001;
// int n, k, q, suf[maxn], equiv[maxn], tmp[maxn];
// vector<int> bucket[maxn];
// string str;
// bool cmp(int a, int b) {
//     return str[a]<str[b];
// }
// void solve() {
//     cin >> str;
//     str+='$';
//     n = str.length(), k = 0;
//     for (int i = 0; i < n; i++) suf[i] = i;
//     sort(suf,suf+n,cmp);
//     int ind = 0;
//     equiv[suf[0]] = 0;
//     for (int i = 1; i < n; i++) equiv[suf[i]] = str[suf[i]]==str[suf[i-1]]?ind:++ind;
//     k = 0;
//     while((1<<k)<n) {
 
//         for (int i = 0; i < n; i++) bucket[i].clear();
//         for (int i = 0; i < n; i++) {
//             bucket[equiv[(suf[i]+(1<<k))%n]].push_back(suf[i]);
//         }
//         ind = 0;
//         for (int i = 0; i < n; i++) {
//             for (int j : bucket[i]) suf[ind++] = j;
//         }
 
 
//         for (int i = 0; i < n; i++) bucket[i].clear();
//         for (int i = 0; i < n; i++) {
//             bucket[equiv[suf[i]]].push_back(suf[i]);
//         }
//         ind = 0;
//         for (int i = 0; i < n; i++) {
//             for (int j : bucket[i]) suf[ind++] = j;
//         }
 
 
//         ind = 0;
//         tmp[suf[0]] = 0;
//         for (int i = 1; i < n; i++) {
//             if (equiv[suf[i]]!=equiv[suf[i-1]]||equiv[(suf[i]+(1<<k))%n]!=equiv[(suf[i-1]+(1<<k))%n])ind++;
//             tmp[suf[i]] = ind;
//         }
//         for (int i = 0; i < n; i++) equiv[i] = tmp[i];
//         k++;
//     }
// }
// int getMaxArea(vector<int> hist, int n) { 
//     stack<int> s; 
//     int max_area = 0;
//     int tp;
//     int area_with_top;
//     int i = 0; 
//     while (i < n) { 
//         if (s.empty() || hist[s.top()] <= hist[i]) {
//             s.push(i++); 
//         } else { 
//             tp = s.top();
//             s.pop();
//             area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1); 
//             if (max_area < area_with_top) max_area = area_with_top; 
//         } 
//     } 
//     while (!s.empty()) { 
//         tp = s.top(); 
//         s.pop(); 
//         area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1);
//         if (max_area < area_with_top) max_area = area_with_top; 
//     } 
//     return max_area; 
// } 
int x;
void solve() {
    cin >> x;
    if (x < 600) {
        cout << "8\n";
    } else if (x < 800) {
        cout << "7\n";
    } else if (x < 1000) {
        cout << "6\n";
    } else if (x < 1200) {
        cout << "5\n";
    } else if (x < 1400) {
        cout << "4\n";
    } else if (x < 1600) {
        cout << "3\n";
    } else if (x < 1800) {
        cout << "2\n";
    } else {
        cout << "1\n";
    }
}
int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int t=1;
    // cin >> t;
    for (int i = 1; i <= t; i++) { 
        // cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}