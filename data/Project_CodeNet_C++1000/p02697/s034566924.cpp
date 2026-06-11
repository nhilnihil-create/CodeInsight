#include<iostream>
#include<vector>
#include<utility>

int main(){
	int n, m;
	std::cin >> n >> m;
	std::vector<std::pair<int, int> > ans;

	if(n % 2){
		for(int l = 1, r = n-1; l < r; l++, r--){
			ans.emplace_back(l, r);
		}
	}else{
		bool flag = false;
		for(int l = 1, r= n-1; l < r; l++, r--){
			if(!flag && r-l <= n/2){
				--r;
				flag = true;
			}
			ans.emplace_back(l, r);
		}
	}

	for(int i=0; i<m; i++){
		std::cout << ans[i].first << " " << ans[i].second << std::endl;
	}
	return 0;
}