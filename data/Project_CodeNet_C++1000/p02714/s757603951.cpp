#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 4e3;
int vis[N+10];
char str[N+10];

int main()
{
	int n;
	scanf("%d",&n);
	scanf("%s",str+1);
	ll ans = 0;
	for(int i=2;i<n;i++){
		if(str[i]=='R'){
			memset(vis,0,sizeof vis);
			int cnt1 = 0,cnt2 = 0,minus = 0;
			for(int j=i+1;j<=n;j++){
				if(str[j]=='G'){
					cnt1++;
					vis[j-i] = 1;
				}
			}
			for(int j=i-1;j>0;j--){
				if(str[j]=='B'){
					cnt2++;
					if(vis[i-j]){
						minus++;
					}
				}
			}
			ans += (cnt1*cnt2-minus);
			memset(vis,0,sizeof vis);
			cnt1 = 0,cnt2 = 0,minus = 0;
			for(int j=i+1;j<=n;j++){
				if(str[j]=='B'){
					cnt1++;
					vis[j-i] = 1;
				}
			}
			for(int j=i-1;j>0;j--){
				if(str[j]=='G'){
					cnt2++;
					if(vis[i-j]){
						minus++;
					}
				}
			}
			ans += (cnt1*cnt2-minus);
		}
		if(str[i]=='G'){
			memset(vis,0,sizeof vis);
			int cnt1 = 0,cnt2 = 0,minus = 0;
			for(int j=i+1;j<=n;j++){
				if(str[j]=='B'){
					cnt1++;
					vis[j-i] = 1;
				}
			}
			for(int j=i-1;j>0;j--){
				if(str[j]=='R'){
					cnt2++;
					if(vis[i-j]){
						minus++;
					}
				}
			}
			ans += (cnt1*cnt2-minus);
			memset(vis,0,sizeof vis);
			cnt1 = 0,cnt2 = 0,minus = 0;
			for(int j=i+1;j<=n;j++){
				if(str[j]=='R'){
					cnt1++;
					vis[j-i] = 1;
				}
			}
			for(int j=i-1;j>0;j--){
				if(str[j]=='B'){
					cnt2++;
					if(vis[i-j]){
						minus++;
					}
				}
			}
			ans += (cnt1*cnt2-minus);
		}
		if(str[i]=='B'){
			memset(vis,0,sizeof vis);
			int cnt1 = 0,cnt2 = 0,minus = 0;
			for(int j=i+1;j<=n;j++){
				if(str[j]=='R'){
					cnt1++;
					vis[j-i] = 1;
				}
			}
			for(int j=i-1;j>0;j--){
				if(str[j]=='G'){
					cnt2++;
					if(vis[i-j]){
						minus++;
					}
				}
			}
			ans += (cnt1*cnt2-minus);
			memset(vis,0,sizeof vis);
			cnt1 = 0,cnt2 = 0,minus = 0;
			for(int j=i+1;j<=n;j++){
				if(str[j]=='G'){
					cnt1++;
					vis[j-i] = 1;
				}
			}
			for(int j=i-1;j>0;j--){
				if(str[j]=='R'){
					cnt2++;
					if(vis[i-j]){
						minus++;
					}
				}
			}
			ans += (cnt1*cnt2-minus);
		}
	}
	printf("%lld\n",ans);
}
