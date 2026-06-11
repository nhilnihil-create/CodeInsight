#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define watch(x) cout << (#x) << " is " << (x) << endl
#define debug cout << "hi" << endl

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const ll MOD = 1e9 + 7;
const int INF32 = 1<<30;
const ll INF64 = 1LL<<60;
const ld pi = 3.141592653589793;

void solve(){
    int n;cin >> n;
    int c[11][11];
    memset(c,0,sizeof(c));
    for(int i = 1;i<=n;i++){
        int f = i;
        int l = i%10;
        //cout << f <<' '<< l <<endl;
        while(f>9){
            f /= 10;
        }
        c[f][l]++;
    }
    int ans = 0;
    for(int i = 0;i<10;i++)
        for(int j = 0;j<10;j++)
        ans += c[i][j]*c[j][i];
        cout << ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
