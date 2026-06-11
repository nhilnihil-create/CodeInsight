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
    ll k; cin >> k;
    bool flag = true;
    char cc = s[0];
    REP(i, s.size()){
        if(s[i] != cc) flag = false;
    }
    if(flag) cout << (s.size()*k)/2 << endl;
    else{
        ll fr=0, bk=0;
        char c1 = s[0];
        REP(i, s.size()){
            if(s[i] != c1){
                break;
            }
            else{
                fr++;
            }
        }
        char c2 = s[s.size()-1];
        for(int i=s.size()-1; i>=0; i--){
            if(s[i] != c2){
                break;
            }
            else{
                bk++;
            }
        }
        ll res = 0;
        ll cnt = 0;
        char c3 = 'A';
        REP(i, s.size()){
            //cout << cnt << endl;
            if(s[i] != c3){
                c3 = s[i];
                res += k*(cnt/2);
                cnt = 1;
            }
            else{
                cnt++;
                if(i == s.size()-1) res += k*(cnt/2);
            }
        }
        //cout << res << endl;
        if(s[0] == s[s.size()-1]) res -= (k-1)*(fr/2 + bk/2 - (fr+bk)/2);
        cout << res << endl;
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
}