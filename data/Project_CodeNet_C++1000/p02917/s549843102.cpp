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
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using uld = unsigned long long;
using P = pair<int,int>;
const int dx[4] = {0,1,0,-1};
const int dy[4] = {1,0,-1,0};
template<class T> inline bool chmax(T &a,T& b){if(a < b){a = b; return true;} else return false;}
template<class T> inline bool chmin(T &a,T& b){if(a > b){a = b; return true;} else return false;}
//struct area

//function area

//main area
int main(){
    int n;
    cin >> n;
    n--;
    if(n == 1){
        int k;
        cin >> k;
        cout << 2*k << endl;
        return 0;
    }
    int ans = 0;
    int b[n];
    rep(i,n){
        cin >> b[i];
    }
    rep(i,n-1){
        ans += min(b[i], b[i+1]);
    }
    ans += b[0] + b[n-1];
    cout << ans << endl;
}
/*

本質：頭と尾の和と、隣り合う二項のminの総和の和が答えっぽい

*/