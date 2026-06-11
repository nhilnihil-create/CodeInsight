#include <bits/stdc++.h>
using namespace std;

#define pii  pair<int, int>
#define vi vector<int >
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define sz(x) (x).size()
#define all(x) (x).begin(), (x).end() //Forward traversal
#define rall(x) (x).rbegin, (x).rend() //reverse traversal

#define ll long long
#define ld long double

const ld EPS = 10e-9;
const int INF = 1e9 + 5;
const long long INFLL = (ll)INF * (ll)INF;
const ll MOD = 1e9 + 7;
const ld PI = 3.14159265358979323846;

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v)
{
    os << "[";
    for (int i = 0; i < (int)v.size(); ++i) {
        os << v[i];
        if (i != (int)v.size() - 1)
            os << ", ";
    }
    os << "]\n";
    return os;
}

template <typename T>
ostream& operator<<(ostream& os, const set<T>& v)
{
    os << "{";
    for (const auto& it : v) {
        os << it;
        if (it != *v.rbegin())
            os << ", ";
    }
    os << "}\n";
    return os;
}

template <typename T>
ostream& operator<<(ostream& os, const unordered_set<T>& v)
{
    os << "{";
    for (const auto& it : v) {
        os << it;
        if (it != *v.rbegin())
            os << ", ";
    }
    os << "}\n";
    return os;
}

template <typename T, typename S>
ostream& operator<<(ostream& os, const map<T, S>& v)
{
    os << "{";
    for (const auto& it : v) {
        os << it.first << " : "
           << it.second;

        if( it != *v.rbegin())
            os  << ", ";
    }

    os << "}\n";
    return os;
}

template <typename T, typename S>
ostream& operator<<(ostream& os, const unordered_map<T, S>& v)
{
    os << "{";
    for (const auto& it : v) {
        os << it.first << " : "
           << it.second;

        if( it != *v.rbegin())
            os  << ", ";
    }

    os << "}\n";
    return os;
}

template <typename T, typename S>
ostream& operator<<(ostream& os, const pair<T, S>& v)
{
    os << "(";
    os << v.first << ", "
       << v.second << ")";
    os << "\n";
    return os;
}

#define DEBUG

#ifdef DEBUG
#define debug(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    cerr << name << " : " << arg1;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define debug(...)
#endif


// __gcd(x, y)

// idea behind binary search: there is monotonically increasing predicate and range [l, r]. Find
// x in range such that x is smallest value for which predicate holds true.
//            int lo = 1, hi = 1e9;
//            while(lo < hi)
//            {
//                ll mid = (lo+hi) / 2;
//                if(predicate(mid))
//                {
//                    hi = mid;
//                }
//                else
//                {
//                    lo = mid+1;
//                }
//            }
//            assert(lo == hi);

// OR: given monotonically decreasing predicate, find x in range such that x is largest value for
// which predicate holds true.

//int x = 0;
//for(int s = max_step; s >= 1; s /= 2)
//{
//    while(predicate(x+s)) x += s;
//}
// after this, x is the largest value for which predicate is true

// How to calculate mid element:
// floor((l+r) / 2) might overflow, use l + floor((r-l)/2)



//ll l = 0, r = s.size()-1;
//ll ans = -1;
//while(l < r)
//{
//    ll mid = l + (r-l) / 2;
//    if(P(mid)) {
//        r = mid;
//        ans = mid;
//    }
//    else
//    {
//        l = mid + 1;
//    }
//}
//
// AND
//
//ll l = 0, r = s.size()-1;
//ll ans = -1;
//while(l <= r)
//{
//    ll mid = l + (r-l) / 2;
//    if(P(mid)) {
//        r = mid-1;
//        ans = mid;
//    }
//    else
//    {
//        l = mid + 1;
//    }
//}
//
// ARE EQUIVALENT

ll f(ll x, ll d)
{
    return x + (ll)ceil((double)d/(x+1));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int s, w;
    cin >> s >> w;
    if(w >= s)
    {
        cout << "unsafe";
    }
    else
    {
        cout << "safe";
    }

    return 0;
}
