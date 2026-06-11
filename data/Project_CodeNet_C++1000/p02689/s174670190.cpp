#include<iostream>
#include<vector>


int main(void){
    int n, m;
    std::cin >> n >> m;
    std::vector<int> h(n);
    for(int i = 0; i < n; i++){
	std::cin >> h[i];
    }
    int a, b;
    std::vector<std::vector<int>> k;
    k.resize(n);
    for(int i = 0; i < m; i++){
	std::cin >> a >> b;
	a--;
	b--;
	k[a].push_back(b);
	k[b].push_back(a);
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
	bool flag = 0;
	for(int j = 0; j < k[i].size(); j++){
	    if(h[i] <= h[k[i][j]]){
		flag = 1;
	    }
	}
	if(!flag) ans++;
    }
    std::cout << ans << std::endl;

    return 0;
}
