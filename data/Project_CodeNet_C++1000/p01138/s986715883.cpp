#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
int n;
int sum[300000];

int main(void){
	while(1){
		scanf("%d",&n);
		if(n==0)break;
		memset(sum,0,sizeof(sum));
		for(int i=0;i<n;i++){
			int h,m,s;
			scanf("%02d:%02d:%02d",&h,&m,&s);
			sum[h*60*60+m*60+s]++;
			scanf("%02d:%02d:%02d",&h,&m,&s);
			sum[h*60*60+m*60+s]--;
		}
		int res=sum[0];
		for(int i=0;i<=24*60*60;i++){
			sum[i+1]+=sum[i];
			res=max(res,sum[i+1]);
		}
		printf("%d\n",res);
	}
	return 0;

}