#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
map<int,int>m;
ll ans;

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int cur;
		scanf("%d",&cur);
		if(m.find(i-cur)!=m.end()){
			ans += m[i-cur];
		}
		m[i+cur]++;
	}
	printf("%lld\n",ans);
}
