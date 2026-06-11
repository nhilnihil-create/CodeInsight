#include<bits/stdc++.h>

#define int long long
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
#define len(a) (int)a.size()
#define all(a) (a).begin(), (a).end()
#define pq priority_queue
#define umap unordered_map
#define uset unordered_set
#define lbound lower_bound
#define ubound upper_bound

#define f_or(i, a, b, s) for (int i=(a); (s)>0?i<(b):i>(b); i+=(s))
#define f_or1(e) f_or(i, 0, e, 1)
#define f_or2(i, e) f_or(i, 0, e, 1)
#define f_or3(i, b, e) f_or(i, b, e, 1)
#define f_or4(i, b, e, s) f_or(i, b, e, s)
#define get5(a, b, c, d, e, ...) e
#define f_orc(...) get5(__VA_ARGS__, f_or4, f_or3, f_or2, f_or1)
#define forr(...) f_orc(__VA_ARGS__)(__VA_ARGS__)

#define FASTIO ios::sync_with_stdio(false) ; cin.tie(0) 

using namespace std ;

using vi   = vector<int> ;
using vs   = vector<string> ;
using vvi  = vector<vi> ;
using pii  = pair<int,int> ;
using vpii = vector<pii>  ;
using mii  = map<int,int> ;
using umii = unordered_map<int,int> ;


template <typename A, typename B>
string to_string(pair<A, B> p);

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);

template <typename A, typename B, typename C, typename D>
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

template <typename A>
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

template <typename A, typename B>
string to_string(pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}

void debug_out() { cout << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cout << " " << to_string(H);
    debug_out(T...);
}

#ifndef ONLINE_JUDGE
#define debug(...) cout<<"LINE ("<< __LINE__ << ") : [" << #__VA_ARGS__ << "] -> ", debug_out(__VA_ARGS__)
#else
#define debug(...)
#endif

int32_t main(){
    FASTIO ;
    double n ;
    cin >> n ;
    int X = ceil(n / (double)1.08); 
    int tax = 0.08 * X ; 
    if(tax + X == n ){
        cout << X; 
    }else{
        cout << ":(";
    }
    return 0 ;
}

