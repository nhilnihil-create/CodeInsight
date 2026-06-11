#include<cstdio>
#include<map>
using namespace std;
int a[200005],b[200005];
map<int,int> mp;
int main(){
	int n,i;
	long long ans=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		b[i]=a[i]+i;
	}
	for(i=1;i<=n;i++){
		ans+=mp[i-a[i]];
		mp[b[i]]++;
	}
	printf("%lld\n",ans); 
	return 0;
}
