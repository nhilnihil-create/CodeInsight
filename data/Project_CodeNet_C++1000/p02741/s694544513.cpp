#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<vector>
#include<complex>
#include<deque>
#define pb push_back
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,b,a) for(int i=b;i>=a;--i)
#define gcd(a,b) __gcd(a,b)
#define MEM(a,x) memset(a,x,sizeof(a))
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int N=1e5+5;
template<class T>inline void read(T &res)
{
char c;T flag=1;
while((c=getchar())<'0'||c>'9')if(c=='-')flag=-1;res=c-'0';
while((c=getchar())>='0'&&c<='9')res=res*10+c-'0';res*=flag;
}
int a[50]={1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51
};
int main(){
	int n;
	cin>>n;
	cout<<a[n-1]<<endl;
	return 0;
}
