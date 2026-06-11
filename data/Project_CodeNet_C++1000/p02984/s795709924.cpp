#include <cstdio>
#include <algorithm>
#include <cstring>
#define ll long long
using namespace std;
int a[100005],ans[100005];
int main(){
	int n,i;
	int tmp;
	scanf("%d",&n);
	for(i=0;i<n;i++){
        scanf("%d",&a[i]);
	}
	for(i=0,tmp=a[0];i<n;i++){
        tmp=a[i]-tmp;
	}
	tmp=tmp+a[0];
	tmp=tmp/2;
	for(i=0;i<n;i++){
	    printf("%d ",tmp*2);
        tmp=a[i]-tmp;

	}
    return 0;
}
