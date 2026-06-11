#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	int k;
	scanf("%d",&k);
//	printf("%d %d\n",nb,nc);
	int cnt=0;
	while(b<=a) cnt++,b*=2;
	while(c<=b) cnt++,c*=2;
//	printf("%d",cnt);
	if(cnt<=k) puts("Yes");
	else puts("No");
	return 0;
}