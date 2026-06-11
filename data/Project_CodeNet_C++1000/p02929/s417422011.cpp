#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <list>
#include <map>
#include <iomanip>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#define fi first
#define se second
#define pb push_back
//#define mp make_pair
#define rep(i,n) for(register int (i)=0;(i)<(n);(i)++)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
const int INF=0x3f3f3f3f;
const int dx[]={0,1,-1,0},dy[]={1,0,0,-1};
const int MOD=1e9+7;
const int N=2e5+10;

inline int read(){
	int ww=1,xx=0;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') ww=-ww;ch=getchar();}
	while(isdigit(ch)){xx=(xx<<1)+(xx<<3)+(ch^48);ch=getchar();}
	return ww*xx;
}

int n;
char s[N];

void init(){
	n=read();
	scanf("%s",s);
}

void solve(){
	LL ans=1,tmp=0;
	for(int i=0;i<2*n;i++){
		if(!(((s[i]=='W')^tmp)&1)) tmp++;
		else ans=1LL*ans*tmp%MOD,tmp--;
	}
	if(tmp) puts("0");
	else {
		for(int i=1;i<=n;i++) ans=1LL*ans*i%MOD;
		printf("%d\n",ans);
	}
}

signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	init();
	solve();
	return 0;
}
