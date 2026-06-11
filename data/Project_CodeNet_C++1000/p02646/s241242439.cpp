#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define INF 0x3f3f3f3f
#define Inf 1000000000000000000LL
#define F first
#define S second
using namespace std;
typedef pair<int,int>pii;
int a,v,b,w,t;
signed main(){
	cin>>a>>v>>b>>w>>t;
	int x=t*(v-w);
	if(x<0)puts("NO");
	else{
		if(abs(a-b)>x)puts("NO");
		else puts("YES");
	}
	return 0;
}
