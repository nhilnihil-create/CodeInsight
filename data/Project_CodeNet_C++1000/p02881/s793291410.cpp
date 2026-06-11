/**
 * @author      : Luis Miguel Baez <es.luismiguelbaez@gmail.com>
 * @created     : Monday July 27, 2020
 */

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
#define piii  tuple<int, int, int>
#define pll   pair<ll, ll>
#define plll  tuple<ll, ll, ll>

#define X  first
#define Y  second

#define debug(...) "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

string to_string(string s) {
    return '"' + s + '"';
}

string to_string(bool b) {
    return (b ? "true" : "false");
}
 
template <typename A, typename B>
string to_string(const pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

// add templates here

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

template<class T>
void println(const T &data) {
#ifndef ONLINE_JUDGE
    cout << to_string((T)data) << endl;
#endif
}

const int MOD = int(1e9+7);
const ll oo  = (ll)(1e9+20);
const ll lloo  = (ll)(1e18)+40;

template<class T>
vector<T> divisors(T number) {
    vector<T> solutions;
    for (T i = 1; i <= sqrt(number); ++i) {
        if (number % i == 0) {
            if (number/i == i) {
                solutions.push_back(i);
            } else {
                solutions.push_back(i);
                solutions.push_back(number/i);
            }
        }
    }
    return solutions;
}

class Task {
public:
    ll N;

    ll solve(istream &in, ostream &out) {
        in >> N;
        if(sqrt(N) == ((ll)sqrt(N))) return (ll)sqrt(N)*2 -2;
        vector<ll> divs = divisors<ll>(N);
        sort(rall(divs));
        ll ans = lloo;
        for(ll i = 0; i < divs.size(); ++i) {
            if(ans > (N/divs[i] + divs[i])) {
                ans = (N/divs[i] + divs[i]) - 2;
            }
        }
        return ans;
    }
    
    void run(istream &in, ostream &out) {
        int t;
        in >> t;
        while(t--) {
            out << solve(in, out) << endl;
        }
    }
};
    
auto main() -> int {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    Task solver;
    istream &in(cin);
    ostream &out(cout);
    cout << solver.solve(in, out) << endl;
    //solver.run(in, out);
    return 0;
}
