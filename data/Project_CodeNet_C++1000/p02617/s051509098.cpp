#include<bits/stdc++.h>
using namespace std;
#define LL long long
int N;
int main(){
	cin>>N;
	LL ans = 0;
	for (int i=1; i<=N; i++) ans += 1LL*i*(N-i+1); 
	for (int i=1; i<=N-1; i++){
		int u,v; cin>>u>>v;
		if (u>v) swap(u,v);
		ans -= 1LL*u*(N-v+1);
	}
	printf("%lld\n",ans);
	return 0;
} 