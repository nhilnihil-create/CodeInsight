#include <bits/stdc++.h>
using namespace std;
#define modulo N
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000

int main(){
	
	int N,M;
	cin>>N>>M;
	
	vector<pair<int,int>> ans;
	
	for(int i=1;true;i++){
		ans.emplace_back(i,mod(i-(2*i-1)));
		if((i+1)*2*2>N){
			int l = i+1;
			int r = mod(i-(2*i-1)-1);
			int m = (l+r)/2;
			for(int j=1;j<N;j++){
				ans.emplace_back(m-j,m+j);
			}
			break;
		}
	}
	
	for(int i=0;i<M;i++){
		cout<<ans[i].first+1<<' '<<ans[i].second+1<<endl;
	}
	
	return 0;
}
