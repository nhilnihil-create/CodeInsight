#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
const int INF = 1001001001;
const int mod = 1000000007;

int main(){
    int h,w;
    int x,y;
    cin >> w >> h >> x >> y;
    double menseki = w * (double)h /2;
    int ans = 0;
    if(w % 2 == 0 && w/2 == x && h%2 == 0 && h/2 == y) ans = 1;
    printf("%.10f %d\n",menseki,ans);
}