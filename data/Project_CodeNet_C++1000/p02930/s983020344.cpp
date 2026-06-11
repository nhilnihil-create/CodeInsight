#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cstdio>
#define LL long long
#define pb push_back
#define mp make_pair
#define INF 0x3f3f3f3f
#define Inf 1000000000000000000LL
#define F first
#define S second
using namespace std;
typedef pair<int,int>pii;
namespace IO{
template<typename T>
void __RI(T&x){
	int ch=getchar(),neg=1;
	x=0;
	for(;!(isdigit(ch)||ch=='-'||ch==EOF);ch=getchar());
	if(ch==EOF)return;
	if(ch=='-')neg=-1,ch=getchar();
	for(;isdigit(ch);ch=getchar())x=x*10+ch-48;
	x*=neg;
}
void R(int&x){__RI(x);}
#ifndef int
void R(int64_t&x){__RI(x);}
#endif
template<typename T1,typename T2>
void R(std::pair<T1,T2>&x){
	R(x.first);
	R(x.second);
}
template<typename T>
void R(std::vector<T>&x){
	for(auto&i:x){R(i);}
}
template<typename T>
void R(T&x){
	std::cin>>x;
}
template<typename T,typename...Args>
void R(T &x,Args&...args){
	R(x),R(args...);
}
template<typename T>
void RA(T *arr,int l,int r){
	arr+=l;
	int p=r-l+1;
	while(p--)R(*arr++);
}
char space=' ';
template<typename T>
void __WI(T x){
	if(x==0)putchar('0');
	if(x<0)putchar('-'),x=-x;
	char ch[64];
	int pos=0;
	while(x)ch[pos++]=x%10+48,x/=10;
	while(pos)putchar(ch[--pos]);
}
void W(){}
void W(const int&x){__WI(x);}
#ifndef int
void W(const int64_t&x){__WI(x);}
#endif
void W(const double&x){printf("%lf",static_cast<double>(x));}
void W(const char&x){putchar(x);}
void W(const std::string&x){printf("%s",x.c_str());}
template<typename T1,typename T2>
void W(const std::pair<T1,T2>&x){
	W(x.first);
	W(space);
	W(x.second);
}
template<typename T>
void W(const std::vector<T>&x){
	for (auto it=x.cbegin();it!=x.cend();it++){
		W(*it);
		W(space);
	}
	W('\n');
}
template<typename T>
void W(const T&x){
	std::cout<<x;
}
template<typename T,typename...Args>
void W(const T&x,const Args&...args){
	W(x),W(space),W(args...);
}
template<typename...Args>
void WL(const Args&...args){
	W(args...),W('\n');
}
template<typename T>
void WA(T *arr,int l,int r){
	arr+=l;
	int p=r-l;
	while(p--)W(*arr++),W(space);
	W(*arr);
}
template<typename T>
void WAL(T *arr,int l,int r){
	arr+=l;
	int p=r-l;
	while(p--)W(*arr++),W(space);
	WL(*arr);
}
}; // namespace IO
int main(){
	int n;
	IO::R(n);
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			int t=1,x=i,y=j;
			while((x%2)==(y%2))x/=2,y/=2,t++;
			IO::W(t);
			IO::W(' ');
		}
		IO::W('\n');
	}
	return 0;
}
