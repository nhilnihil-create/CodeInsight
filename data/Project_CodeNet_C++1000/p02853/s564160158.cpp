#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll mod = 1e9+7;

int main(){
    int x,y;
    cin >> x >> y;
    int ans = 0;
    int mon[3] = {300000,200000,100000};
    if(x == 1 && y == 1) ans += 400000;
    if(x < 4) ans += mon[x-1];
    if(y < 4) ans += mon[y-1];
    cout << ans << endl;
    return 0;
}