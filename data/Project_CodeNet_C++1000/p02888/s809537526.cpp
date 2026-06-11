#include <cstdio>
#include <algorithm>
#include <cstring>
#define ll long long
using namespace std;
int l[2005];
int cnt[2005][2005];
int main(){
	int n,i,j,ans=0,low,high;

	scanf("%d",&n);
	for(i=0;i<n;i++){
        scanf("%d",&l[i]);
	}

	for(i=0;i<n;i++){//[i,n-1]
        for(j=i;j<n;j++){
            cnt[i][l[j]]++;
        }
        for(j=1;j<2005;j++){
            cnt[i][j]+=cnt[i][j-1];
            //printf("cnt[%d][%d]=%d",i,j,cnt[i][j]);
        }
	}

	for(i=0;i+2<n;i++){
        for(j=i+1;j+1<n;j++){

            high=l[i]+l[j];
            if(l[i]>l[j]) low=l[i]-l[j];
            else low=l[j]-l[i];
            //printf("%d %d:%d<x<%d %d\n",l[i],l[j],low,high,cnt[j+1][high-1]-cnt[j+1][low]);
            if(cnt[j+1][high-1]-cnt[j+1][low]>0) ans+=cnt[j+1][high-1]-cnt[j+1][low];
        }
	}
	printf("%d\n",ans);
    return 0;
}
