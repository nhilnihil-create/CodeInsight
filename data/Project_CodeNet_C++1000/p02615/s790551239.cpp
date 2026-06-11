#include<bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(),(x).end()

using ll = long long;
using P = pair<int,int>;
using mp =  map<string,int>;

const int MOD = 1e9 + 7;
const int INF = 1001001001;


int main(){

    int n, a[200005];
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        scanf("%d", &a[i]);
    }

    sort(a, a + n, greater<int>());

    ll ans = 0;
    for(int i = 1; i < n; ++i){
        ans += a[i / 2];
    }

    cout << ans << "\n";

    return 0;
}
