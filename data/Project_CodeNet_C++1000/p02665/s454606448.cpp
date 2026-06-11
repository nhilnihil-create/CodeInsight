#include <bits/stdc++.h>
using namespace std;

#define ris   return *this
#define tmplt template<class T
#define dbgo  debug& operator<<
tmplt > struct rge { T b, e; };
tmplt > rge<T> range(T i, T j) { return rge<T>{i, j}; }
struct debug {
#ifdef LOCAL
~debug(){cerr<<endl;}
tmplt > dbgo(T x){cerr<<boolalpha<<x;ris;}
tmplt, class C > dbgo(pair<T, C> x){ris<<"("<<x.first<<", "<<x.second<<")";}
tmplt > dbgo(rge<T> x){*this<<"[";for(auto it=x.b;it!=x.e;it++){*this<<", "+2*(it==x.b)<<*it;}ris<<"]";}
tmplt > dbgo(vector<T> x){ris<<range(x.begin(),x.end());}
#else
tmplt > dbgo(const T&){ris;}
#endif
};
#define nav(...) << "[ " << #__VA_ARGS__ ": " << (__VA_ARGS__) << " ] "
using ll = long long;

#define forn(i, n) for(int i = 0; i < int(n); i++)
#define ford(i, n) for(int i = n-1; i >= 0; i--) 

template<typename T> 
void min_self(T& a, T b) { 
    a = min(a, b); 
}
template<typename T>
void max_self(T& a, T b) { 
    a = max(a, b); 
}

void no() {
    cout << "-1\n";
    exit(0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    ++n;
    vector<ll> a(n);
    forn(i, n) cin >> a[i];
    if(n == 1) {
        cout << (a[0] == 1 ? 1 : -1) << '\n';
        exit(0);
    }
    if(a[0] == 1) {
        no();
    }
    vector<ll> suf(n);
    suf[n-1] = a[n-1];
    for(int i = n-2; i >= 0; i--) {
        suf[i] = suf[i+1] + a[i];
    }
    ll ans = 1;
    ll prev = 1;
    for(int i = 1; i < n; i++) {
        ll can_have = 2*prev;
        ll maybe = suf[i];
        min_self(can_have, maybe);
        debug() nav(i) nav(can_have);
        if(can_have < a[i]) {
            no();
        }
        else {
            ans += can_have;
        }
        prev = can_have - a[i]; // can you have children
    }
    
    cout << ans << endl;
}













// Spend more time thinking, it won't hurt

// Read statement carefully
// Solve on paper first!
// Make your infinity big enough
// Overflows (long long)

// Author: blondie
