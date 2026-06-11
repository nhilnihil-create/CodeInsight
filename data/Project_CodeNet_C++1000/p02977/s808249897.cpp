#include<bits/stdc++.h>
int n,last,nb,cou[5],cnt;
bool vis[100005];
int main()
{
	scanf("%d",&n);
	for(int N=1;N<=n;N<<=1){if(N==n) return 0*puts("No");vis[N]=1;}
	puts("Yes");
	puts("1 2");
	puts("2 3");
	printf("3 %d\n",1+n);
	printf("%d %d\n",n+1,n+2);
	printf("%d %d\n",n+2,n+3);
	if(n%4==3) {
		for(int i=4;i<=n;i+=4)
		{
			printf("%d %d\n",i-1+n,i);
			for(int j=i;j<i+3;j++) printf("%d %d\n",j,j+1);
			printf("%d %d\n",i+3,i+n);
			for(int j=i+n;j<i+n+3;j++) printf("%d %d\n",j,j+1);
		}
		return 0;
	}
	for(int i=4;i+3<=n;i+=4)
	{
		for(int j=i;j<i+3;j++) printf("%d %d\n",j,j+1);
		printf("%d %d\n",i+3,i+n);
		for(int j=i+n;j<i+n+3;j++) printf("%d %d\n",j,j+1);
	}
	for(int i=n;i%4!=3;i--) cou[++cnt]=i;
	if(vis[cou[cnt]]&&cnt==3) {
		int U=cou[cnt];
		printf("%d %d\n%d %d\n",U+1,U+2,U+1+n,U+2+n);
		printf("%d %d\n%d %d\n",U+2,3,U+1+n,3);
		printf("%d %d\n%d %d\n",U,1+n,U+n,U+2);
		for(int i=4;i+3<=n;i+=4)
			printf("%d %d\n",i-1+n,i);
		return 0;
	}
	for(int i=cnt;i>=2;i--) printf("%d %d\n%d %d\n",cou[i],cou[i-1],cou[i]+n,cou[i-1]+n);
	last=cou[cnt]+n;
	for(int i=1;i<=4-cnt;i++) nb^=cou[1]+i;
	if(nb%4)
	{
		printf("%d %d\n",last,nb%4);
		last=nb%4;
	}
	else printf("%d 1\n",last);
	for(int i=4;i+3<=n;i+=4)
	{
		printf("%d %d\n",last,i);
		if(vis[i]&&((nb/i)&1)) last=i;
	}
	printf("%d %d\n",last,cou[1]);
	return 0;
}