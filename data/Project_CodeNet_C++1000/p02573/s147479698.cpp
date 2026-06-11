#include<bits/stdc++.h>
using namespace std;
#define Maxn 200005
int n,m,ai,bi,fa[Maxn],cnt = 1,ans = 1;
int find(int r){
	if (fa[r] != r)
		fa[r] = find(fa[r]);
	return fa[r]; 
}
int main(){
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
		fa[i] = i;
	for(int i = 1;i <= m;i++){
		cin >> ai >> bi;
		int r1 = find(ai);
		int r2 = find(bi);
		fa[r1] = r2;
	}
	for(int i = 1;i <= n;i++)
		fa[i] = find(fa[i]);
	sort(fa + 1,fa + 1 + n);
	for(int i = 2;i <= n;i++)
		if (fa[i] == fa[i - 1]){
			cnt++;
			ans = max(ans,cnt);
		}
		else
			cnt = 1;
	cout << ans << endl;
	return 0;	
}