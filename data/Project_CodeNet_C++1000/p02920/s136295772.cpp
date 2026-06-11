#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double db;
typedef pair<int,int> pii;
const int N=10000;
const db pi=acos(-1.0);
#define lowbit(x) (x)&(-x)
#define sqr(x) (x)*(x)
#define rep(i,a,b) for (register int i=a;i<=b;i++)
#define per(i,a,b) for (register int i=a;i>=b;i--)
#define fir first
#define sec second
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define maxd 998244353
#define eps 1e-8
#define iter multiset<int>::iterator
int m,n,goal[(1<<18)+5],now[(1<<18)+5];
multiset<int> s;

int read()
{
    int x=0,f=1;char ch=getchar();
    while ((ch<'0') || (ch>'9')) {if (ch=='-') f=-1;ch=getchar();}
    while ((ch>='0') && (ch<='9')) {x=x*10+(ch-'0');ch=getchar();}
    return x*f;
}

int main()
{
	m=read();n=(1<<m);
	rep(i,1,n) goal[i]=read();
	rep(i,1,n) s.insert(goal[i]);
	iter tmp=s.end();tmp--;now[1]=*tmp;s.erase(tmp);
	int len=1;
	//cout << goal[1] << endl;
	rep(i,1,m)
	{
		int pre=len;
		rep(j,1,pre)
		{
			iter it=s.lower_bound(now[j]);
			if (it==s.begin())
			{
				puts("No");
				return 0;
			}
			else
			{
				it--;int tmp=*it;
				s.erase(it);
				now[++len]=tmp;
			}
		}
		sort(goal+1,goal+1+len);
		reverse(goal+1,goal+1+len);
		//rep(j,1,len) cout << now[j] << " ";cout << endl;
	}
	puts("Yes");
	return 0;
}