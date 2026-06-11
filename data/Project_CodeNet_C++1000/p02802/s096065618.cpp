#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define watch(x) cout << (#x) << " is " << (x) << endl
#define debug cout << "hi" << endl

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const int MOD = 1e9 + 7;
const int INF32 = 1<<30;
const ll INF64 = 1LL<<60;

void solve(){
    int n,m;cin >> n >> m;
    vector<bool>b(n+1,0);
    vector<int>t(n+1,0);
    for(int i = 0;i<m;i++){
        int a;string s;
        cin >> a >> s;
        if(s=="WA"&&b[a]==0) t[a]++;
        if(s=="AC") b[a] = 1;
    }
    int ans = 0;int p = 0;
    for(int i = 0;i<=n;i++){
        if(b[i]){
            ans++;
            p += t[i];
        }
    }
    cout << ans <<' '<<p;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}