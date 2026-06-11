#include<bits/stdc++.h>
#define lint long long
#define st first
#define nd second
#define INF 0x3f3f3f3f
#define MOD 1000000007

using namespace std;


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, m; cin>>n>>m;
	
	vector<lint> b(n+1,1);
	vector<lint> pd(n+1,1);
	pd[0] = 1;
	
	for(int i=0;i<m;i++){
		int x; cin>>x;
		b[x]=0;
	
	}
	pd[1]=b[1];
	
	for(int i=2;i<=n;i++){
		pd[i] = (pd[i-1]*b[i-1] + pd[i-2]*b[i-2])%MOD;
	}
	cout<<pd[n]<<"\n";
	

	return 0;	
}
