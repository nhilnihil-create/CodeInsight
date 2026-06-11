#include<iostream>
#include<vector>
#include<cmath>
#include<iomanip>

class Permutation{
public:
    int n;
    std::vector<int> used, tmp;
    std::vector<std::vector<int>> perm_vector;
    int k;
    int total;

    Permutation(int _n, int _k) : n(_n), k(_k), used(n) {
	total = 0;
	permutation(0);
    }

    void permutation(int cnt){
	if(cnt == k){
	    total++;
	    perm_vector.push_back(tmp);
	    return;
	} 
	
        for(int i = 0; i < n; i++){
	    if(used[i] != 1){
		tmp.push_back(i);
	    	used[i] = 1;
	    	permutation(cnt+1);
		used[i] = 0;
		tmp.pop_back();
	    }
	}
    }
};

// 
// }

int main(void){
    // int n;
    // a.resize(k);
    // permutation()
    int n;
    std::cin >> n;
    std::vector<std::pair<int, int>> coordinate(n);
    for(int i = 0; i < n; i++){
	std::cin >> coordinate[i].first >> coordinate[i].second;
    }

    Permutation all_index = Permutation(n, n);
    double total, ans, tmp;
    for(int i = 0; i < all_index.perm_vector.size(); i++){
        tmp = 0;
        for(int j = 1; j < all_index.perm_vector[i].size(); j++){
	    int before = all_index.perm_vector[i][j-1];
	    int after = all_index.perm_vector[i][j];
	    int ax = coordinate[before].first;
	    int ay = coordinate[before].second;
	    int bx = coordinate[after].first;
	    int by = coordinate[after].second;
            tmp += std::sqrt((ax - bx) * (ax - bx) + (ay - by) * (ay - by));
        }
	total += tmp;
    }
    ans = total / all_index.total;
    std::cout << std::fixed << std::setprecision(15) << ans << std::endl;
    return 0;
}
