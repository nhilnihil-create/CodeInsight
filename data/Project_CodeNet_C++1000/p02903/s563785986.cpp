#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
int INF = 1000000009;
int main()
{
    int h,w,a,b;
    std::cin >> h >> w >> a >> b;
    int v[h][w];
    rep(i,h){
        rep(j,w){
            v[i][j] = ((i < b && j < a) || (i >= b && j >= a)) ? 0 :1;
        }
    }
    rep(i,h){
        rep(j,w){
            std::cout << v[i][j];
        }
        std::cout << std::endl;
    }
}