#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 5;
const ll INF = 2e18;

int n;
int main(){
    #ifdef Irene
    freopen("in.txt", "r", stdin);
    #endif // Irene
    ios_base::sync_with_stdio(false);

    cin >> n;
    ll a, b, s = 0, ans = 0;
    for(int i = 1;i <= n;i++){
        cin >> a >> b;
        s += a * b;
        ans += b;
    }
    s -= 9;
    if(s <= 0)s = 0;
    else s = s / 9ll + (s%9 > 0);
    cout << ans + s - 1 << endl;
}
