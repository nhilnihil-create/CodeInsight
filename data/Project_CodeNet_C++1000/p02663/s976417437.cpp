#include <bits/stdc++.h>
using namespace std;

#define watch(x) cerr << (#x) << ": " << (x) << endl

typedef long long LL;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int ha, ma, hb, mb, k; cin >> ha >> ma >> hb >> mb >> k;

    int a = ha*60 + ma, b = hb*60 + mb;

    int ans = (b-a) - k;

    cout << ans << '\n';
    
    return 0;
}
