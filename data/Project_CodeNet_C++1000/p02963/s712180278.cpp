#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main(){
    ll s;
    cin >> s;
    ll x0=0,y0=0;
    ll x1=1e9,y1=1;
    ll x2,y2;
    y2 = s/x1 + 1;
    if(y2==1e9+1) y2--;
    x2 =x1*y2-s;
    printf("%d %d %d %d %d %d\n",x0,y0,x1,y1,x2,y2);
    return 0;
}