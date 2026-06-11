// 16:46

#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
#define int long long
#define MOD 1000000007
typedef vector<int> vi;
typedef pair<int,int> pi;
#define inf 1e18
#define For(i,a,b) for (int i = a; i < b; i++)
#define Rep(i,a,b) for (int i = a; i <= b; i++)
#define ps(x,y) fixed << setprecision(y) << x 
#define pb push_back 
#define mp make_pair 
 
int32_t main()
{
    fast;
    double n, ans = -1; cin >> n;
    Rep(i, 1, n) {
        if((int) (i * 1.08) == n) ans = i;
    }

    if(ans != -1) cout << ans;
    else cout << ":(";
    
    
    
    return 0;
}