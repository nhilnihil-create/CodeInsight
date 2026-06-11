#include <bits/stdc++.h>
template<class T> inline bool chmin(T&a, T b){if(a > b){a = b; return true;}else{return false;}}
template<class T> inline bool chmax(T&a, T b){if(a < b){a = b; return true;}else{return false;}}
#define ll long long
#define double long double
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)
#define mod (ll)(1e9+7)
#define inf (ll)(3e18+7)
#define pi (double) acos(-1.0)
#define P pair<int,int>
#define PiP pair<int,pair<int,int>>
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
using namespace std;

vector<int> Z_Algorithm(string s){
    int n = s.size(), l = -1, r = -1;
    vector<int> a(n, 0);
    a[0] = n;
    for(int i = 1; i < n; i++){
        int &same = a[i];
        if(l != -1){
            same = min(r-i, a[i-l]);
            same = max(0, same);
        }
        while(same < n && s[i+same] == s[same])same++;
        if(r < i+same){
            r = i+same;
            l = i;
        }
    }
    return a;
}

int main() {
    int n;
    string s;
    cin >> n >> s;
    int ans = 0;
    while(s.size() > 0){
        vector<int> z = Z_Algorithm(s);
        for(int i = 0; i < s.size(); i++){
            if(z[i] < i+1)chmax(ans, z[i]);
        }
        s.erase(s.begin());
    }
    cout << ans << endl;
}