#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;
int n, m, a[N], b[N], fa[N], cnt;
int get(int x){return fa[x] == x? x : fa[x] = get(fa[x]);}
int main()
{
    std::ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) fa[i] = i;
    for(int i = 1; i <= m; i++)
    {
    	cin >> a[i] >> b[i];
    	int ga = get(a[i]), gb = get(b[i]);
    	fa[gb] = ga;
	}
	for(int i = 1; i <= n; i++) if(get(i) == i) cnt++;
	cout << cnt - 1 << endl;
	return 0;
}
