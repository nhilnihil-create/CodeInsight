#include<bits/stdc++.h>
#define ts cout<<"ok"<<endl
#define int long long
#define hh puts("")
#define pc putchar
//#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
//char buf[1<<21],*p1=buf,*p2=buf;
using namespace std;
const int N=100005;
int n,m,k,p,ans,a[N],r[N],sum[N];
inline int read(){
    int ret=0,ff=1;char ch=getchar();
    while(!isdigit(ch)){if(ch=='-') ff=-1;ch=getchar();}
    while(isdigit(ch)){ret=ret*10+(ch^48);ch=getchar();}
    return ret*ff;
}
void write(int x){if(x<0){x=-x,pc('-');}if(x>9) write(x/10);pc(x%10+48);}
void writeln(int x){write(x),hh;}
void writesp(int x){write(x),pc(' ');}
//m´Î¿Ï¶¨È«ÓÃÔÚiÉÏ,a[i]±ä³Éa[i]+m
//×î¶àÓÐp-1¸ö´óÓÚa[i]+m  
//k¸öÊý,ÏÈÈ«·ÖÅä¸ø ´óÓÚa[i]+mµÄ ºÍ Ð¡ÓÚµÈÓÚa[i]µÄ
//Éè»¹Ê£x¸ö¿ÉÒÔ·ÖÅä 
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	n=read(),m=read(),k=read(),p=read();
	for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	r[n]=n;
	for(int i=n-1;i>=1;i--){
		if(a[i]==a[i+1]) r[i]=r[i+1];
		else r[i]=i;
	}
	int pos=p;
	while(pos+1<=n&&a[pos+1]==a[p]) pos++;
	ans=pos;
	for(int i=pos+1;i<=n;i++){
		if(a[i]+m>=a[p]){
			int cnt=k-(n-i+1)-(p-1);
			if(cnt<=0){
				ans=r[i];
				i=r[i];
			}
			else{
				if((a[i]+m)*(i-p)-(sum[i-1]-sum[p-1])>=cnt*m){
					ans=r[i];
					i=r[i];
				}
				else break;
			}
		}
		else break;
	}
	writeln(ans);
    return 0;
}