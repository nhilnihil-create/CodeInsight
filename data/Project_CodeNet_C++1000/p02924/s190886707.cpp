#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
typedef pair<int,int> P;
struct edge{int to, id;};
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define mod 1000000007

using graph = vector<vector<ll>>;

int main(){
    ll n;
    cin >> n;
    ll ans = n * (n-1) / 2;
    cout << ans << endl;
    return 0;
}