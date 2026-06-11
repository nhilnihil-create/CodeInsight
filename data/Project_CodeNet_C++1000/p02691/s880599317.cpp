#include<bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(),(x).end()

using ll = long long;
using P = pair<int,int>;
using mp =  map<string,int>;

const int MOD = 1e9 + 7;
const int INF = 1001001001;


int main(void){

    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; ++i){
        int x;
        cin >> x;
        a[i] = -(x + i + 1);
        b[i] = x - (i + 1);
    }

    sort(all(a));
    sort(all(b));

    ll ans = 0;
    for(int i = 0; i < n; ++i){
        ans += upper_bound(all(b), a[i]) - lower_bound(all(b), a[i]);
    }

    cout << ans << "\n";

    return 0;
}
