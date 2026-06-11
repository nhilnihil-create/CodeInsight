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
    int a, b;
    cin >> a >> b;
    int ans = -1;
    rep(i, 10000){
        if(i * 2 / 25 == a && i / 10 == b){
            ans = i;
            break;
        }
    }
    cout << ans << endl;
}
/*

[N * 0.08] = A
[N * 0.10] = B
を満たす最小の自然数Nを求める
1 <= B <= 100なので、
シミュレーションすればできそう
おそらく 1000 + α まで計算すればいいけど、余裕をもって10000
O(1)でもできそう

*/