#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i,j,k) for(int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for(int i=(int)(j);i>=(int)(k);i--)
inline ll read(){
	ll x=0;char ch=getchar();bool f=0;
	for(;!isdigit(ch);ch=getchar()) if(ch=='-') f=1;
	for(;isdigit(ch);ch=getchar()) x=x*10+ch-'0';
	return f?-x:x;
}
void write(ll x){
	if(x<0) putchar('-'),x=-x;
	if(x>=10) write(x/10);putchar(x%10+'0');
}
void writeln(ll x){write(x);puts("");}
void writep(ll x){write(x);putchar(' ');}
int main(){
	int n=read();
	cout<<(n-1)/2;
	return 0;
}
