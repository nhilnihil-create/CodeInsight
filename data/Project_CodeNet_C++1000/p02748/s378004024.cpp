#include <iostream>
#include <algorithm>
#include <cmath>
#include <limits>
#include <iomanip>
#include <vector>
#include <cstring>
#include <queue>
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
const int INF = 1e6;
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using uld = unsigned long long;
using P = pair<int,int>;
const ll mod = 1e9+7;
const int dx[4] = {0,1,0,-1};
const int dy[4] = {1,0,-1,0};
template<class T> inline bool chmax(T &a,T& b){if(a < b){a = b; return true;} else return false;}
template<class T> inline bool chmin(T &a,T& b){if(a > b){a = b; return true;} else return false;}
int main(){
    int a,b,m;
    cin >> a >> b >> m;
    int num_a[a],num_b[b];
    int min_a=INF,min_b=INF;
    rep(i,a){
        cin >> num_a[i];
        min_a = min(min_a,num_a[i]);
    }
    rep(i,b){
        cin >> num_b[i];
        min_b = min(min_b,num_b[i]);
    }
    int x[m],y[m],c[m];
    rep(i,m){
        int x0,y0;
        cin >> x0 >> y0 >> c[i];
        x0--; y0--;
        x[i] = x0; y[i] = y0;
    }
    int ans = min_a + min_b;
    rep(i,m){
        ans = min(ans, num_a[x[i]] + num_b[y[i]] - c[i]);
    }
    cout << ans << endl;
}