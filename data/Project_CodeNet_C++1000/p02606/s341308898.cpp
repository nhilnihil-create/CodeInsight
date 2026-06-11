#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define All(V) V.begin(), V.end()
typedef long long int ll;
typedef pair<int, int> P;
const ll MOD = 1e9+7, INF = 1e9;

//しっかり制約確認したか?
int main()
{
    int l, r, d; cin >> l >> r >> d;
    int ans = 0;
    for(int i = l; i <= r; i++){
        if(i % d == 0)ans++;
    }
    cout << ans << endl;
    system("pause");
}
