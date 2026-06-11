#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
#define  deb(x) cout << #x << " - " << x << "\n";

const int N = 105;

int n, m, q, ans = 0;
int a[N], b[N], c[N], d[N];
int cur[N];

void gen(int idx)
{
    if(idx>n){
        int temp = 0;
        for(int i=1;i<=q;++i){
            if(cur[b[i]] - cur[a[i]] == c[i]) temp += d[i];
        }
        ans = max(ans,temp);
        return;
    } 
    for(int i = cur[idx-1];i<=m;++i){
        cur[idx] = i;
        gen(idx+1);
    }
}

int32_t main()
{
	IOS;
	cin >> n >> m >> q;
	for(int i = 1; i <= q; i++)
		cin >> a[i] >> b[i] >> c[i] >> d[i];
	cur[0] = 1;
	gen(1);
	cout << ans;
	return 0;
}
