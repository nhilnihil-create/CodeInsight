#include<bits/stdc++.h>
#define mo 1000000007
#define pi 3.1415926535898
#define eps 1e-9 
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
long long n,m,i,j;
void lj(long long u,long long v){
	pus(u,1);
	pus(v,2);
	return;
}
int main(){
    n=read();
    m=n;
    while((m&1)==0)
    	m>>=1;
    if(m==1){
    	printf("No\n");
    	return 0;
    }
    printf("Yes\n");
    for(i=3;i<=n;i+=2){
    	lj(i-1,i);
    	lj(i,1);
    	lj(1,i-1+n);
    	lj(i-1+n,i+n);
    }
    lj(n+1,2);
    if((n&1)==0){
    	for(i=1;i<n;i++)
    		if((i^1^n)<n){
    			j=(i^1^n);
    			if((i&1)==0)
    				i+=n;
    			if((j&1)==0)
    				j+=n;
    			lj(i,n);
    			lj(j,n<<1);
    			return 0;
    		}
    }
    return 0;
}