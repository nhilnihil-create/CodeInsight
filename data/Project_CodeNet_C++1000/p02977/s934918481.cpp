#include<bits/stdc++.h>
#define fo(i,l,r) for(int i=l;i<=r;i++)
#define of(i,l,r) for(int i=l;i>=r;i--)
#define fe(i,u) for(int i=head[u];i;i=e[i].next)
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
inline void open(const char *s)
{
	#ifndef ONLINE_JUDGE
	char str[20];
	sprintf(str,"%s.in",s);
	freopen(str,"r",stdin);
//	sprintf(str,"%s.out",s);
//	freopen(str,"w",stdout);
	#endif
}
inline int rd()
{
	static int x,f;
	x=0;f=1;
	char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')f=-1;
	for(;ch>='0'&&ch<='9';ch=getchar())x=x*10+ch-'0';
	return f>0?x:-x;
}
const int N=100010;
int n;
vector<pii>vec;

int Main()
{
	if(n==(n&-n))return puts("No"),0;
	fo(i,1,2)vec.emplace_back(i,i+1);
	vec.emplace_back(3,n+1);
	fo(i,1,2)vec.emplace_back(n+i,n+i+1);
	for(int i=4;i<n;i+=2){
		vec.emplace_back(1,i);
		vec.emplace_back(i,i+1);
		vec.emplace_back(1,n+i+1);
		vec.emplace_back(n+i+1,n+i);
	}
	if(~n&1){
		int x,y;
		fo(i,2,n-1)if((n^i^1)<n){x=i;y=n^i^1;break;}
		if(x&1)vec.emplace_back(n+x,n);
		else vec.emplace_back(x,n);
		swap(x,y);
		if(x&1)vec.emplace_back(n+x,n+n);
		else vec.emplace_back(x,n+n);
	}
	cout<<"Yes\n";
	for(auto x:vec)cout<<x.first<<' '<<x.second<<'\n';
	return 0;
}

int main()
{
	while(scanf("%d",&n)!=EOF)Main();
	return 0;
}
