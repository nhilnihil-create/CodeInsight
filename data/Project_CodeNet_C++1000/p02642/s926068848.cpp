#include <bits/stdc++.h>
#define MOD 1000000007LL
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int n;
int a[200005];
bool flag[1000005];
int cnt[1000005];

int main(void){
	scanf("%d",&n);
	int ans=0;
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		cnt[a[i]]++;
	}
	sort(a,a+n);
	for(int i=0;i<n;i++){
		if(!flag[a[i]]){
			if(cnt[a[i]]<=1)ans++;
			for(int j=a[i];j<=1000000;j+=a[i]){
				flag[j]=true;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
