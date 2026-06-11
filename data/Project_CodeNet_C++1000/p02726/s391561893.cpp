#include<bits/stdc++.h>
#define inf 1000000000
#define mod 1000000007
#define pb push_back
#define sz(v) (v).size()
#define all(v) (v).begin(),(v).end()
#define mp make_pair
#define fi first
#define se second
using namespace std;
template <class T> void chmax(T &x,T y){x=x>y?x:y;return;}
template <class T> void chmin(T &x,T y){x=x<y?x:y;return;}
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pi;

int n,x,y;
int cnt[2005];

int getdis(int s,int t)
{
	if(s<=x&&t>=y) return x-s+t-y+1;
	if(s<=x&&t<=x||s>=y&&t>=y) return t-s;
	if(s>x&&t<y) return min(s-x+y-t+1,t-s);
	if(s>=x&&s<=y&&t>=y) return min(t-y+1+s-x,t-s);
	if(s<=x&&t>=x&&t<=y) return min(x-s+1+y-t,t-s);
	return 0;
}

int main()
{
	scanf("%d%d%d",&n,&x,&y);
	if(x>y) swap(x,y);
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			cnt[getdis(i,j)]++;
	for(int k=1;k<=n-1;k++)
		printf("%d\n",cnt[k]); 
	return 0;
}