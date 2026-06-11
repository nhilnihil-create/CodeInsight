// Made by Luis Miguel Baez
// es.luismiguelbaez@gmail.com

#include <bits/stdc++.h>
 
using namespace std;

#define endl '\n'
#define precise(n,k) fixed << setprecision(k) << n
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define uint  unsigned int
#define ll    long long
#define ull   unsigned long long
#define ld    long double

#define pii   pair<int, int>
#define piii  pair<int, pair<int, int>>
#define pll   pair<ll, ll>

#define F  first
#define S  second
#define PB push_back
#define MP make_pair

#define debug(...) "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

string to_string(string s) {
    return '"' + s + '"';
}

string to_string(bool b) {
    return (b ? "true" : "false");
}
 
template <typename A, typename B>
string to_string(pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename T>
string to_string(const vector<T> &v) {
    bool first = true;
    string res = "{";
    for (const T &x : v) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string((T)x);
    }
    res += "}";
    return res;
}

// add templates here

template<class T>
void println(const T &data) {
    cout << to_string((T)data) << endl;
}

template <typename T>
void write(vector<T> &v, bool size=true) {
    if(size) cout << v.size() << endl;
    string res = "";
    for(const T &x: v) {
        res += to_string((T)x) + " ";
    }
    cout << res << endl;
}

template <typename T>
void read(vector<T> &v) {

    for(const T &x: v) {
        cin >> x;   
    }
}

const int MOD = int(1e9+7);
const int oo  = int(1e9 + 20);
const ll lloo  = (ll)(1e18 + 10);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> val(n+1);
    vector<int> sorted;
    for(int i = 1; i <= n; ++i) {
        cin >> val[i];
        sorted.push_back(val[i]);
    }
    sort(all(sorted));
    
    for(int i = 1; i <= n; ++i) {
        if(val[i] != sorted[n-1]) {
            cout << sorted[n-1];
        } else {
            cout << sorted[n-2];
        }
        cout << endl;
    }
    

    return 0;
}