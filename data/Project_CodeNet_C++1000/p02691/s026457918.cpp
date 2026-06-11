#include<iostream>
#include<set>
#include<map>
#include<vector>

int main(void){
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    std::multiset<int> m;
    std::map<int, int> map;
    int key;
    for(int i = 0; i < n; i++){
	std::cin >> a[i];
	key = i + a[i];
	if(map.find(key) == map.end()){
	    map[key] = 1;
	}else{
	    map[key]++;
	}
    }
    long long ans = 0;
    for(int i = n-1; i >= 1; i--){
	key = i - a[i];
	if(map.find(key) != map.end() && map[key] != 0){
	    int key2 = i + a[i];
	    map[key2] -= 1;
	    ans += map[key];
	}
    }
    std::cout << ans << std::endl;
    return 0;
}

