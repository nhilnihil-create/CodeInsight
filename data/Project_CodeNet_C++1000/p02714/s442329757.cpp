#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1e9;
const ll MOD = 1e9 + 7;


int main(){
    int n;
    string s;
    cin >> n >> s;

    ll r = 0, g = 0, b = 0;
    for(auto c: s){
        r += (c == 'R');
        g += (c == 'G');
        b += (c == 'B');
    }

    ll ans = r * g * b;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            int k = j + (j-i);
            if(k<n && s[i] != s[j] && s[j] != s[k] && s[i] != s[k]) ans--;
        }
    }

    cout << ans << endl;
}