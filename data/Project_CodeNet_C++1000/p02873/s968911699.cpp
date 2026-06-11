#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
typedef long long ll;
#define pb push_back
#define fi first
#define se second
#define ALL(x) (x).begin(),(x).end()
#define RALL(x) (x).rbegin(),(x).rend()
template <class T, class U> ostream &operator<<(ostream &os, const pair<T, U> &p){os<<"("<<p.first<<","<< p.second<<")";return os;}
template <class T> ostream &operator<<(ostream &os, const vector<T> &v){os<<"{";REP(i,(int)v.size()){if(i)os<<",";os<<v[i];}os<<"}";return os;}
template <typename T, size_t S> void printArray(const T (&array)[S]){for(auto val : array)std::cout << val << ", ";std::cout << "\n";}
void Yes() {cout << "Yes" << endl;}
void No() {cout << "No" << endl;}
void YES() {cout << "YES" << endl;}
void NO() {cout << "NO" << endl;}
const double PI=acos(-1);
const ll MOD = 1000000007;
using Graph = vector<vector<int>>;
//const int dx[4] = {1, 0, -1, 0};
//const int dy[4] = {0, 1, 0, -1};
//const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
//const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

void solve(){
    string s; cin >> s;
    ll n = s.size() + 1;
    vector<ll> a(n, 0);
    ll cnt = 0;
    s = '.' + s;
    for(int i=n-1; i>=1; i--){
        if(s[i] == '>'){
            a[i] = cnt;
            if(s[i-1] == '>'){
                cnt++;
            }
            else cnt = 0;
        }
        else cnt = 0;
    }
    //cout << a << endl;
    if(s[1] == '<') a[0] = 0;
    else a[0] = a[1] + 1;
    cnt = 1;
    for(int i=1; i<=n-2; i++){
        if(s[i] == '<'){
            if(s[i+1] == '<'){
                a[i] = cnt;
                cnt++;
            }
            else{
                a[i] = max(a[i+1] + 1, cnt);
                cnt = 1;
            }
        }
        else cnt = 1;
    }
    if(s[n-1] == '<') a[n-1] = cnt;
    //cout << a << endl;
    ll res = 0;
    REP(i, n) res += a[i];
    cout << res << endl;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
}