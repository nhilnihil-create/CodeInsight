#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vp;
const int inf = 1e9;
const ll INF = 1e18;
const db eps = 1e-10;

#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define ep emplace
#define mem(a) memset(a, 0, sizeof(a))
#define copy(a, b) memcpy(a, b, sizeof(b))
#define PA cout << "pass\n"
#define lowbit(x) (x & -x)
#define all(x) x.begin(), x.end()
#define TM cout << db(clock()) / CLOCKS_PER_SEC << '\n'

mt19937 mrand(chrono::high_resolution_clock::now().time_since_epoch().count());

template <class A, class B>
string to_string(pair<A, B> p);

template <class A, class B, class C>
string to_string(tuple<A, B, C> p);

template <class A, class B, class C, class D>
string to_string(tuple<A, B, C, D> p);

string to_string(const string& s) {
    return '"' + s + '"';
}

string to_string(const char* s) {
    return to_string((string) s);
}

string to_string(bool b) {
    return (b ? "true" : "false");
}

string to_string(vector<bool> v) {
    bool first = true;
    string res = "{";
    for (int i = 0; i < static_cast<int>(v.size()); i++) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(v[i]);
    }
    res += "}";
    return res;
}

template <size_t N>
string to_string(bitset<N> v) {
    string res = "";
    for (size_t i = 0; i < N; i++) {
        res += static_cast<char>('0' + v[i]);
    }
    return res;
}

template <class A>
string to_string(A v) {
    bool first = true;
    string res = "{";
    for (const auto &x : v) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}

template <class A, class B>
string to_string(pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <class A, class B, class C>
string to_string(tuple<A, B, C> p) {
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}

template <class A, class B, class C, class D>
string to_string(tuple<A, B, C, D> p) {
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}

void debug(){cerr << endl;}
template<class T, class... U>
void debug(const T& h,const U&... t){
    cerr << to_string(h) << ' ';
    debug(t...);
}

int a, b, n;

int main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(10);
    cin >> a >> b >> n;
    cout << (n + max(a, b) - 1) / max(a, b) << '\n';
    return 0;
}