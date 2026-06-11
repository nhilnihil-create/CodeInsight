#include<iostream>
#include<vector>
#include<set>

int main(void){
    int n, a, x, y;

    std::cin >> n;
    std::vector<std::vector<std::pair<int, int>>> st(n);
    std::set<int> ss;

    for(int i = 0; i < n; i++){
	std::cin >> a;
	for(int j = 0; j < a; j++){
	    std::cin >> x >> y;
	    x--;
	    st[i].push_back(std::make_pair(x, y));
	}
    }

    bool f;
    int ans = 0;
    int cnt;
    for(int i = 0; i < 1<<n; i++){
	f = true;
	ss.clear();
	for(int j = 0; j < n; j++){
	    if(i & (1<<j)){
		ss.insert(j);
	    }
	}
	for(auto j = ss.begin(); j != ss.end(); j++){
	    for(int k = 0; k < st[*j].size(); k++){
		int tx = st[*j][k].first;
		int ty = st[*j][k].second;
		if(ty == 0 && ss.find(tx) != ss.end()){
		    f = false;
		    break;
		} 
		if(ty == 1 && ss.find(tx) == ss.end()){
		    f = false;
		    break;
		} 
	    }
	} 
	if(f){
	    int size = ss.size();
	    ans = std::max(ans, size);
	} 
    }
    std::cout << ans << std::endl;
    return 0;
}

