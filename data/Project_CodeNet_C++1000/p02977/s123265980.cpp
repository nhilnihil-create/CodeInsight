#include<bits/stdc++.h>
#define ts cout<<"ok"<<endl
#define ll long long
#define hh puts("")
#define pc putchar
//#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
//char buf[1<<21],*p1=buf,*p2=buf;
using namespace std;
int n;
inline int read(){
    int ret=0,ff=1;char ch=getchar();
    while(!isdigit(ch)){if(ch=='-') ff=-ff;ch=getchar();}
    while(isdigit(ch)){ret=(ret<<3)+(ret<<1)+ch-'0';ch=getchar();}
    return ret*ff;
}
void write(int x){
    if(x<0){x=-x;putchar('-');}
    if(x>9) write(x/10);
    putchar(x%10+48);
}
void writeln(int x){write(x),hh;}
void writesp(int x){write(x),pc(' ');}
void add(int x,int y){
	writesp(x),writeln(y);
}
signed main(){
	n=read();
	for(int i=0;i<=18;i++){
		if(n==(1<<i)){
			printf("No");
			return 0;
		}
	}
	puts("Yes");
	if(n&1){
		for(int i=2;i<=n;i+=2){
			add(i,i+1);
			add(i+1,1);
			add(1,i+n);
			add(i+n,i+n+1);
		}
		add(1+n,2);
		return 0;
	}
	else{
		for(int i=2;i<=n-1;i+=2){
			add(i,i+1);
			add(i+1,1);
			add(1,i+n);
			add(i+n,i+n+1);
		}
		add(1+n,2);
		int t;
		for(int i=18;i>=0;i--){
			if(n&(1<<i)){
				t=i;
				break;
			}
		}
		int to=(1<<t)+1;
		add(n,to);
		add(n+n,(n^(to-1))+n);
	}
    return 0;
}