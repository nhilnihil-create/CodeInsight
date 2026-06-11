/*input
10 4 8
*/
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,x,y;
    cin >> n >> x >> y;
    vector<int>ans(n);
    for(int i = 1;i<=n;i++){
        for(int j = i+1;j<=n;j++){
            int dis = j-i;
            dis = min(dis,abs(j-y)+abs(i-x)+1);
            ans[dis]++;
        }
    }
    for(int i = 1;i<n;i++) cout << ans[i] <<endl;
    return 0;
}