#include <iostream>
#include <algorithm>
#include <cmath>
#include <limits>
#include <iomanip>
#include <vector>
#include <cstring>
#include <queue>
#include <map>
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
    int n;
    cin >> n;
    int h[n];
    rep(i,n) cin >> h[i];
    int ans = 0;
    int count = 0;
    rep(i,n-1){
        if(h[i] >= h[i+1]){
            count++;
        }
        else{
            ans = max(ans,count);
            count = 0;
        }
        if(i == n-2) ans = max(ans,count);
    }
    cout << ans << endl;
}