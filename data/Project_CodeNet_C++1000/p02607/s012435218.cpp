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
    int n; cin >> n;
    int ans = 0;
    vector<int> v(n);
    rep(i, n){
        cin >> v[i];
        if((i+1) % 2 == 1 && v[i] % 2 == 1)ans++;
    }
    cout << ans << endl;
    system("pause");
}
