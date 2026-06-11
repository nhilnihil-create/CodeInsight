#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
typedef vector<int> vi;
#define endl '\n'
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define rf(i,a,b) for(int i=a;i>=b;i--) 
#define fast_io ios_base::sync_with_stdio(0);
#define show(x) cout<<x<<endl;
#define pret(x) cout<<x<<endl; return 0;
#define disp(x) cout<<x<<" ";
#define let(x,y) cout<<x<<" "<<y<<endl;
ll MOD=1e9+7;
const int maxn=2e5+5;

int32_t main(){
    fast_io;
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; ++i)
    {
    	cin >> a[i];
    }
    sort(a, a + n);
    int ans = 0;
    for (int i = 0; i < k; ++i)
    {
    	ans += a[i];
    }
    show(ans);
    return 0;
}