#include<bits/stdc++.h>
#define lint long long
#define st first
#define nd second
#define INF 0x3f3f3f3f

using namespace std;


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int x;
	int n;
	vector<int> p(110);
	cin>>x>>n;
	
	int dif = abs(-1-x);
	int ans = -1;
	while(n--){
		int y; cin>>y;
		p[y] = 1;
	
	}
	
	for(int i=0;i<103;i++){
		if(p[i])continue;
		if(abs(i-x) < dif){
			ans = i;
			dif = abs(i-x);
		}
	}
	cout<<ans<<"\n";

	return 0;	
}
