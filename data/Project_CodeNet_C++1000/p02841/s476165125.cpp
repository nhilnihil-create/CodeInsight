#include<cstdio>
#include<cstring>
#define in inline
#define re register
using namespace std;
in int read() {
	re int t=0;
	re char v=getchar();	
	while(v<'0'||v>'9'){
	v=getchar();
	}	
	while(v>='0'&&v<='9'){		
	t=(t<<3)+(t<<1)+(v^48);		
	v=getchar();	}
	return t;
}
int a,b,c,d;
int main(){
a=read();
b=read();
c=read();
d=read();
if(a!=c)puts("1");
else puts("0");
}
