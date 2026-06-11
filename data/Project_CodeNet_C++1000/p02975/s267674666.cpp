#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define REP(i,n) for (int i = 1; i < (int)(n); i++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define vout(x) rep(i,x.size()) {cout << x[i] << " "; cout << endl;}
template<class T> bool chmin(T &a, T b) {if(a>b) {a=b;return 1;}return 0;}
template<class T> bool chmax(T &a, T b) {if(a<b) {a=b;return 1;}return 0;}
using namespace std;
using vint = vector<int>;
using vvint = vector<vector<int>>;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<int,int>;
const int inf = 1e9;
const ll inf_l = 1e18;
const int MAX = 1e5;

int main() {
    int n; cin >> n;
    map<int,int> mp;
    rep(i,n) {
        int x; cin >> x;
        mp[x]++;
    }
    if (n % 3 != 0) {
        if (mp[0] != n) cout << "No" << endl;
        else cout << "Yes" << endl;
    } else {
        if (mp.size() > 3) cout << "No" << endl;
        else if (mp.size() == 3) {
            bool ok = true;
            int x = 0;
            for (P p : mp) {
                x ^= p.first;
                if (p.second != n/3) ok = false;
            }
            if (ok && x == 0) cout << "Yes" << endl;
            else cout << "No" << endl;
        } 
        else if (mp.size() == 1) {
            if (mp[0] == n) cout << "Yes" << endl;
            else cout << "No" << endl;
        } else {
            bool ok = true;
            for (P p : mp) {
                if (p.first == 0 && p.second != n/3) ok = false; 
                if (p.first != 0 && p.second != (n/3)*2) ok = false;
            }
            if (ok) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
}