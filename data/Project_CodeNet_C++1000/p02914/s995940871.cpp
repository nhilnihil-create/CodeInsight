#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

#define p_ary(ary,a,b,i) do { cout << "["; for (int (i) = (a);(i) < (b);++(i)) cout << ary[(i)] << ((b)-1 == (i) ? "" : ", "); cout << "]\n"; } while(0)
#define p_map(map,it) do {cout << "{";for (auto (it) = map.begin();;++(it)) {if ((it) == map.end()) {cout << "}\n";break;}else cout << "" << (it)->first << "=>" << (it)->second << ", ";}}while(0)

void hakidashi(vector<ll>& a) {
    int n = a.size(),m = 60;
    int i = 0;
    for (int j = 59;j >= 0;--j) {
        if (((a[i]>>j)&1)^1) for (int k = i;k < n;++k) if ((a[k]>>j)&1) {
            swap(a[i],a[k]);
            break;
        }
        if ((a[i]>>j)&1) {
            for (int s = 0;s < n;++s) if (i != s && ((a[s]>>j)&1)) a[s] ^= a[i];
            i++;
            if (i == n) break;
        }
    }
}

int main() {
    int n;
    ll sum = 0;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0;i < n;++i) {
        cin >> a[i];
        sum ^= a[i];
    }
    for (int i = 0;i < 60;++i) if ((sum>>i)&1) for (int j = 0;j < n;++j) if ((a[j]>>i)&1) a[j] ^= (1LL<<i);
    hakidashi(a);
    ll ans = 0;
    for (int i = 0;i < n;++i) ans ^= a[i];
    cout << ans*2+sum << endl;
    /*
    for (int i = 0;i < n;++i) {
        for (int j = 0;j < 60;++j) cout << ((a[i]>>j)&1);
        cout << endl;
    }
    p_ary(a,0,n,i);
    */
}