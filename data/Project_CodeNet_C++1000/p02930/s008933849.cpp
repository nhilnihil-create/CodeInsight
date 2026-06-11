#include <bits/stdc++.h>
using namespace std;
using Int = int_fast64_t;

Int n;
vector<vector<Int>> ans;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n;
	ans.resize(n, vector<Int>(n, -1));
	for(Int i=0; (1ll<<i)<=n; ++i){
		for(Int j=1; j<=n; ++j){
			for(Int k=j+1; k<=n; ++k){
				if((j&((1<<i)-1)) == (k&((1<<i)-1))){
					ans[j-1][k-1] = i+1;
				}
			}
		}
	}
	for(Int i=0; i<ans.size(); ++i)
		for(Int j=i+1; j<ans[i].size(); ++j)
			cout << ans[i][j] << " \n"[j+1==ans[i].size()];
}