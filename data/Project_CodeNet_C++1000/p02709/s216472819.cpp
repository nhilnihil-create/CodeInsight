#include<iostream>
#include<cstdio>
#include<string>
#include<ctime>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<stack>
#include<climits>
#include<queue>
#include<map>
#include<set>
#include<sstream>
using namespace std;
typedef long long ll;   
typedef unsigned long long ull;
const int MAXN=2000;
inline long long read()//inline 加速读入
{
	long long x=0;char c=getchar();//x代表返回值，c代表读取的字符
	while (c<'0'||c>'9') c=getchar();//读取所有非数部分
	while (c>='0'&&c<='9') x=x*10+c-'0',c=getchar();//如果读取的字符为数，加入返回值
	return x;
}
ll n,k,t,aa[MAXN+10][MAXN+10];
struct hh{
	ll x;
	int y;
}a[MAXN+10];
int cmp(hh a,hh y)
{
	return a.x>y.x;
}
ll run(int l,int r){
	if(l>r)return 0;
	if(aa[l][r])return aa[l][r];
	int i=n-(r-l);
	return aa[l][r]=max(run(l,r-1)+a[i].x*abs(r-a[i].y),run(l+1,r)+a[i].x*abs(a[i].y-l)) ; 
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		a[i].x=read();a[i].y=i;
	}
	sort(a+1,a+n+1,cmp);
	run(1,n);
	cout<<aa[1][n]<<endl;
} 