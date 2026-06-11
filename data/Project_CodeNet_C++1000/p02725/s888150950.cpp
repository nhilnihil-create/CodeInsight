#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cmath>
#include<stack>
#include<queue>
using namespace std;
typedef long long ll;

const int maxn = 200090;

int n,k,m;
int a[maxn],d[maxn];

ll read(){ ll s=0,f=1; char ch=getchar(); while(ch<'0' || ch>'9'){ if(ch=='-') f=-1; ch=getchar(); } while(ch>='0' && ch<='9'){ s=s*10+ch-'0'; ch=getchar(); } return s*f; }

int main(){
    k = read(), n = read();
    for(int i = 1;i <= n;i++) {
    	a[i] = read();
	}
	
	for(int i = 1 ;i <= n;i++) {
		d[i]=a[i]-a[i-1];
	}
	for(int i=1 ;i <= n;i++){
		m=max(m,d[i]);
	}
	m=max(m,k-a[n]+a[1]);
		
	printf("%d\n",k-m);
	return 0;
}