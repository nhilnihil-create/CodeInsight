#include <bits/stdc++.h>
#define ll long long
#define _n 2020
#define C continue
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define gc getchar
#define pc putchar
#define kg putchar(' ')
#define hh putchar('\n')
#define mem(a,b) memset(a,b,sizeof(a))
#define _for(i,a,b) for( int i=(a); i<=(b); i++)
#define _rep(i,a,b) for( int i=(a); i>=(b); i--)
using namespace std;
inline int rd()
{
    int x=0,f=1;char ch=gc();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=gc();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=gc();}
    return x*f;
}
char ch[200];
inline void rt(int x )
{
    int cnt=0,tmp=x>0?x:-x;
    if (!x) {pc('0');return;}
    if(x<0) pc('-');
    while(tmp>0) {ch[cnt++]=tmp%10+'0';tmp/=10;}
    while(cnt>0) pc(ch[--cnt]);
}
int main()
{
	int k=rd();
	_for(i,1,k)
	{
		printf("ACL");
	}

    return 0;
}



