
#include <cstdio>
#include <algorithm>
#include <cstring>
#define maxn 200010
using namespace std;
struct node{
	char s[12];
}q[maxn];
char pre[12];
int cmp(node a,node b){
	return strcmp(a.s,b.s)<0;
}
int main(){
	int n,i,cnt=1;
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%s",q[i].s);
	sort(q+1,q+1+n,cmp);
	strcpy(pre,q[1].s);
	for(i=2;i<=n;i++)
		if(strcmp(q[i].s,pre)!=0)strcpy(pre,q[i].s),cnt++;
	printf("%d\n",cnt);
	return 0;
}