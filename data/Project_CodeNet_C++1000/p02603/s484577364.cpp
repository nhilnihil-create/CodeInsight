#include<bits/stdc++.h>
using namespace std;
#define int long long
#define Int int32_t
#define all(c) c.begin(), c.end()
#define FAST ios_base::sync_with_stdio(false) , cin.tie(NULL);
#define pii pair<int,int>
#define pb push_back
#define F first
#define S second
#define endl "\n"
#define bitcnt(n) __builtin_popcountll(n)
#define setpre(n) cout << fixed << setprecision(n)
#define tr(c) for(const auto& x : c )cout << x << " "; cout << "\n";
#define ol(c, s, e) for(int pos=s; pos<e; pos++)cout << c[pos] << " ";cout <<"\n";
#define PI acos(-1LL)



#ifndef CF
string to_string(const string& s){
    return '"' + s + '"';
}
string to_string(const char* s) {
    return to_string((string) s);
}
string to_string(bool b) {
    return (b ? "true" : "false");
}
template <typename A, typename B>
string to_string(pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename T>
string to_string(T v){
    bool first = true;
    string res = "{";
    for(const auto& x: v){
        if(!first) res+=", ";
        first = false;
        res+=to_string(x);
    }
    res+="}";
    return res;
}
void bug() { cerr << endl; }
template<typename Head, typename... Tail>
void bug(Head H, Tail... T) {
    cerr << " " << to_string(H);
    bug(T...);
}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", bug(__VA_ARGS__);
#endif


const int M = 1000000007;
const int N = 2e6 + 5;
const long long INF = 2e18 + 12;


void solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int &x: v) cin >> x;
    int money = 1000;
    for(int i=0; i<n-1; i++){
        int stocks = money/v[i];
        money+=stocks*max(v[i+1] - v[i], 0LL);
    }
    cout << money << endl;
}

signed main(){
    FAST
    clock_t start;
    double duration;
    start = clock();

    int tc = 1;
//    TODO: check for tc
//    cin >> tc;
    for (int t = 1; t <= tc; t++) {
  //      cout << "Case #" << t << ": ";
        solve();
    }
#ifndef LOCAL
    duration = (clock() - start) / (double) CLOCKS_PER_SEC;
    cerr <<"\nTotal time elapsed: "<< duration <<"sec\n";
#endif
}
