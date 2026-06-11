#include<bits/stdc++.h>
 
#define rep(i,n) for(ll i = 0;i < n;++i)
#define all(v) v.begin(),v.end()
using namespace std;
using ll = long long;
typedef pair<int,int> P;
 
const int INF = 1001001001;
const long double PI = (acos(-1));
const int mod = 1e9+7;
const int vx[6] = {0,1,0,-1,1,-1};
const int vy[6] = {1,0,-1,0,1,1};

ll f(ll a){
    ll rep = 0;
    for(ll i = 1;i <= a/2;++i){
        if(a%i == 0){
            rep++;
        }
    }
    return rep+1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int D;
    cin >> D;
    vector<int> c(26);
    rep(i,26) cin >> c[i];
    vector<vector<int>> s(D,vector<int> (26,0));
    rep(i,D){
        rep(j,26){
            cin >> s[i][j];
        }
    }
    vector<int> last(26,0);
    int ans = 0;
    rep(i,D){
        int t;
        cin >> t;
        last[t-1] = i+1;
        ans += s[i][t-1];
        int tmp =  0;
        rep(j,26){
            tmp += c[j] * (i+1-last[j]);
        }
        ans -= tmp;
        cout << ans << endl;   
    }
    

    
    
    cout << endl;
    return 0;
}
