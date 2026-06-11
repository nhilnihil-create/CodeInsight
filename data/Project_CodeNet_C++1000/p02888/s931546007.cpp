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
     vector<int>a(n);
     for(int i = 0;i<n;i++) cin >> a[i];
     sort(a.begin(),a.end());
     int ans = 0;
     for(int i = 0;i<n-2;i++){
        int k = i+2;
        for(int j = i+1;j<n-1;j++){
            while(a[i]+a[j]>a[k]&&k!=n) k++;
            ans += k - j -1;
        }
     }
     cout << ans;

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}