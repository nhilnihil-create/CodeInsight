#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
#define MAXN 200007
int a[MAXN];
bool cnt[1000007];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for(int i=0; i<n; i++) {
		cin >> a[i];
	}
	sort(a,a+n);
	memset(cnt,0,sizeof cnt);
	long long ans=0;
	for(int i=0; i<n; i++) {
		int now=a[i];
		//ans+=cnt[now];
		if(cnt[now]==0 && (i+1>=n || a[i]!=a[i+1])) ans++;
		if(i==0 || a[i]!=a[i-1])
		for(int j=now; j<=1000000; j+=now) {
			cnt[j]=1;
		}
	}
	cout << ans << '\n';
}
