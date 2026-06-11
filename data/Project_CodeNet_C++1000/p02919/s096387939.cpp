#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define rep(i,n) for (int i = 0; i < (n); i++)
#define sz(x) int(x.size())
const ll mod = 1000000007;
const ll INF = 10010010010010010;

int main() {
    int n; cin >> n;
    int a[n];
    int idx[n];
    rep(i,n) {
        cin >> a[i];
        a[i]--;
        idx[a[i]] = i;
    }
    //rep(i,n) {printf("%d ", idx[i]);} printf("\n");
    multiset<int> Set;
    for (ll i = -1; i < n+1; i++) Set.insert(i);
    Set.insert(-1); Set.insert(n);
    ll ans = 0;
    rep(i,n-1) {
        int p = idx[i];
        auto itr = Set.find(p);
        auto itr2 = itr; itr2--;
        auto itr3 = itr; itr3++;
        auto itr1 = itr2; itr1--;
        auto itr4 = itr3; itr4++;
        int p1 = (*itr1);
        int p2 = (*itr2);
        int p3 = (*itr3);
        int p4 = (*itr4);
        //printf("%d %d %d %d %d\n", p1,p2,p,p3,p4);
        ans += ((ll)i+1)*((p2-p1)*(p3-p)+(p4-p3)*(p-p2));
        //cout << ans << endl;
        Set.erase(p);
    }
    cout << ans << endl;
    return 0;
}
