#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int main(void)
{
	int i,n,a[100],b[100],cnt=1,l=0,k=0,cnt2=0;
	scanf("%d",&n);
	for(i=0;i<n;i++) scanf("%d %d",&a[i],&b[i]);
	for(i=0;i<n;i++){
		if(a[i]==b[i]){
			cnt2++;
			if(cnt2==1) l=i;
			else{
				if(l+1==i){
					l=i;
					cnt++;
				}
			}
			if(cnt==3) k=1;
		}
		else{
			cnt=1;
			cnt2=0;
		}
	}
	if(k==1) printf("Yes\n");
	else printf("No\n");
	return 0;
}