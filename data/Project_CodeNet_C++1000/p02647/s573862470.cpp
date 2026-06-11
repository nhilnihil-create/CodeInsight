#include <bits/stdc++.h>
#define LL long long
#define pb push_back
#define mp make_pair
#define INF 0x3f3f3f3f
#define Inf 1000000000000000000LL
#define F first
#define S second
using namespace std;
typedef pair<int,int>pii;
int n,a[200010];
int k,cnt[200010];
int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=k;i++){
		bool flg=1;
		int cur=0;
		for(int i=1;i<=n;cnt[i]=0,i++){
			if(a[i]!=n)flg=0;
		}
		if(flg)break;
		for(int i=1;i<=n;i++){
			cnt[max(1,i-a[i])]++;
			cnt[min(n+1,i+a[i]+1)]--;
		}
		for(int i=1;i<=n;i++){
			cur+=cnt[i];
			a[i]=cur;
		}
	}
	for(int i=1;i<=n;i++)cout<<a[i]<<" ";
}
