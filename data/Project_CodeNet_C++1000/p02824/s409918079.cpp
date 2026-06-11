#include<cstdio>
#include<algorithm>
const int N=1e5+3;
int n,m,v,p,a[N],s;long long b[N];
bool Cmp(const int&a,const int&b){return a>b;}
int main(){
	scanf("%d%d%d%d",&n,&m,&v,&p);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	std::sort(a+1,a+1+n,Cmp);
	for(int i=1;i<=n;i++)b[i]=a[i]+b[i-1];
	for(int i=1,j=1;i<=n;i=j){
	  for(;j<=n&&a[j]>=a[i];j++);
	  if(i<=p){s+=j-i;continue;}
	  if(a[i]+m<a[p])continue;
	  if(v-(p-1)-(n-j+1)-1<=0){s+=j-i;continue;}
	  s+=(j-i)*((v-(p-1+n-j+2))*(long long)m+b[j-2]-b[p-1]<=(long long)(a[i]+m)*(j-p-1));
	}printf("%d\n",s);
	return 0;
}