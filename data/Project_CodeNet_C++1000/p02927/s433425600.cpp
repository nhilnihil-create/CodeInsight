#include <bits/stdc++.h>
using namespace std;
template<class t> inline t read(t &x){
	x=0;char c=getchar();bool f=0;
	while(!isdigit(c)) f|=c=='-',c=getchar();
	while(isdigit(c)) x=(x<<1)+(x<<3)+(c^48),c=getchar();
	if(f) x=-x;return  x;
}
template<class t> inline void write(t x){
	if(x<0){putchar('-'),write(-x);}
	else{if(x>9)write(x/10);putchar('0'+x%10);}
}




int m,d,ans;


signed main(){
	read(m);read(d);
	for(int i=1;i<=m;i++)
		for(int j=1;j<=d;j++) if(i==(j%10)*(j/10)&&(j%10)>=2&&j/10>=2)
			ans++;//,printf("%d-%d\n",i,j);
	write(ans);
}