#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <random>
#include <cstdio>
#include <cmath>
#include <climits>
#include <map>
#include <queue>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int) n; i++)
#define rep1(i, n) for(int i = 1; i <= (int) n; i++)

int main() {
    int n,x,y;
    cin >> n >> x >> y;
    vector<int> ans(n-1); // 最短距離がkである(i,j)の組ans[k-1]個
    rep1(i,n) {
        rep1(j,n) {
            if (i <= j) break;
            int d = n;

            // 頂点x,yの間の辺を利用しない場合(一直線)
            d = min(d, abs(i-j));
            // i -> x -> y -> jの順
            d = min(d, abs(i-x)+1+abs(j-y));
            // i -> y -> x -> jの順
            d = min(d, abs(i-y)+1+abs(j-x));
        
            ans[d-1]++;
        }
    }
    rep(i,n-1) {
        cout << ans[i] << endl;
    }
}