#include <cstdio>
#include <vector>
using namespace std;
int n,cnt;
void insertion(int a[],int g){
	for(int i=g;i<n;i++){
		int v=a[i];
		int j=i-g;
		for(;j>=0&&a[j]>v;){
			a[j+g]=a[j];
			j-=g;
			cnt++;
		}
		a[j+g]=v;
	}
}
void shell(int a[]){
	cnt=0;
	int m=0,tem=1;
	vector<int> g;
	while(1){
		g.push_back(tem);
		m++;
		tem=tem*3+1;
		if(tem>=n)	break;
	}
	printf("%d\n",m);
	for(int i=m-1;i>=0;i--){
		insertion(a,g[i]);
		if(i!=m-1)	printf(" ");
		printf("%d",g[i]);
	}
	printf("\n%d\n",cnt);
}
int main(){
	scanf("%d",&n);
	int a[n];
	for(int i=0;i<n;i++)	scanf("%d",&a[i]);
	shell(a);
	for(int i=0;i<n;i++)	printf("%d\n",a[i]);
	printf("\n");
	return 0;
}