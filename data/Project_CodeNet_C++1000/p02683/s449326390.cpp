#include<iostream>
#include<vector>

const static int INF = 1001001001;

int main(void){
    int n, m, x;
    std::cin >> n >> m >> x;
    std::vector<int> c(n);
    std::vector<std::vector<int>> w;
    w.resize(n);

    for(int i = 0; i < n; i++){
	w[i].resize(m+1);
	for(int j = 0; j <= m; j++){
	    std::cin >> w[i][j];
	}
    }

    int ans = INF;
    std::vector<int> tmp(m+1, 0);
    bool flag = 0;

    for(int i = 0; i < (1 << n); i++){
	for(int j = 0; j < n; j++){
	    if(i & (1 << j)){
		for(int k = 0; k < m+1; k++){
		    tmp[k] += w[j][k];
		}
	    }else{
	    }
	}
	for(int j = 1; j <= m; j++){
	    if(tmp[j] < x){
		flag = 1;
		break;
	    }
	}
	// for(int j = 0; j <= m; j++){
	//     std::cout << tmp[j] << " ";
	// }
	// std::cout << std::endl;

	if(flag == 0 && tmp[0] < ans){
	    ans = tmp[0];
	}
	flag = 0;
	for(int j = 0; j <= m; j++){
	    tmp[j] = 0;
	}
    }
    if(ans == INF) std::cout << -1 << std::endl;
    else std::cout << ans << std::endl;
    return 0;
}
