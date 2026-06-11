#include <bits/stdc++.h>
using namespace std;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

#define rep(i,cc,n) for(int i=cc;i<n;++i)
#define lrep(i,cc,n) for(long long i=cc;i<n;++i)
#define sqrep(i,cc,n) for(long long i=cc;i*i<=n;++i)
#define rrep(i,cc,n) for(long i=cc;i>n;--i)
#define pii pair<int, int>
#define pll pair<long long, long long>
 
using ll = long long;

const vector<int> dx = {1, 0, -1, 0};
const vector<int> dy = {0, 1, 0, -1};
const ll inf = 1001001001;
const ll e9  = 1000000000;
const ll mod = 1000000007;

int main(){
    int n, a, b, c, d;
    string road;
    cin >> n >> a >> b >> c >> d >> road;
    a--;
    b--;
    c--;
    d--;
    bool q = true;
    rep(i, a+1, c+1){
        if(road[i]=='#' && road[i-1]=='#'){
            cout << "No" << endl;
            return 0;
        }
    }
    rep(i, b+1, d+1){
        if(road[i]=='#' && road[i-1]=='#'){
            cout << "No" << endl;
            return 0;
        }
    }
    if(c<d){
        cout << "Yes" << endl;
        return 0;
    }else{
        rep(i, b, d+1){
            if(i-1<0 || i+1>=n)continue;
        if(road[i+1]=='.' && road[i]=='.' && road[i-1]=='.'){
            cout << "Yes" << endl;
            return 0;  
        }
        }
    }
    cout << "No" << endl;
    return 0;
}