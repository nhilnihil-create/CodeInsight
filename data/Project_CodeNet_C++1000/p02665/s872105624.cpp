#include<bits/stdc++.h>
#define maxn 1000000000000000LL
using namespace std;
long long read(){
    long long xx=0,flagg=1;
    char ch=getchar();
    while((ch<'0'||ch>'9')&&ch!='-')
        ch=getchar();
    if(ch=='-'){
        flagg=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        xx=xx*10+ch-'0';
        ch=getchar();
    }
    return xx*flagg;
}
void pus(long long xx,long long flagg){
    if(xx<0){
        putchar('-');
        xx=-xx;
    }
    if(xx>=10)
        pus(xx/10,0);
    putchar(xx%10+'0');
    if(flagg==1)
        putchar(' ');
    if(flagg==2)
        putchar('\n');
    return;
}
long long n,i,a[100005],b[100005],sum,ans;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read();
	for(i=0;i<=n;i++)
		a[i]=read();
	sum=1;
	for(i=0;i<=n;i++)
		b[i]=maxn;
	for(i=0;i<=n;i++){
		b[i]=sum;
		if(sum<a[i]){
			pus(-1,2);
			return 0;
		}
		sum-=a[i];
		sum<<=1;
		if(sum>=maxn)
			break;
	}
	sum=0;
	for(i=n;i>=0;i--){
		sum+=a[i];
		if(sum>b[i])
			sum=b[i];
		ans+=sum;
	}
	pus(ans,2);
    return 0;
}