#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
typedef long long ll;

int main(){
    double n;
    cin >> n;
    // 切り上げ
    int ans = ceil(n/1.08);
    // 切り捨て
    if(floor(ans*1.08) == n) cout << ans << endl;
    else cout << ":(" << endl;
    return 0;
}