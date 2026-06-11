#include<bits/stdc++.h>
#define pb push_back
#define sz(v) (v).size()
#define all(v) (v).begin(),(v).end()
#define mp make_pair
#define fi first
#define se second
#define inf 1000000000
#define mod 1000000007
using namespace std;
template <class T> void chmax(T &x,T y){x=x>y?x:y;return;}
template <class T> void chmin(T &x,T y){x=x<y?x:y;return;}
typedef long long ll;
typedef unsigned long long ull;

int n,m;

int main()
{
	scanf("%d%d",&n,&m);
	printf("%d\n",n*max(0,n-1)/2+m*max(0,m-1)/2);
	return 0;
}