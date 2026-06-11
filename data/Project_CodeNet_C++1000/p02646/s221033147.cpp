#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define All(V) V.begin(), V.end()
typedef long long int ll;
typedef pair<int, int> P;
const ll MOD = 1e9+7, INF = 1e9;

int main()
{
    ll a, b, v, w, t;
    cin >> a >> v >> b >> w >> t;
    if(v <= w){
        cout << "NO" << endl;
        return 0;
    }
    ll d = v-w;
    ll k = abs(a-b);
    if(k <= d * t){
        cout << "YES" << endl;
    }
    else cout << "NO" << endl;
    system("pause");
}