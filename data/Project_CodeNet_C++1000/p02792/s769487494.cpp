#include<iostream>
#include<map>

std::pair<int, int> make_sf_pair(int n){
    int f;
    std::pair<int, int> cur;
    cur.second = n % 10;
    while(n != 0){
	f = n;
	n /= 10;
    }
    cur.first = f;
    return cur;
}

int main(void){
    int n;
    std::map<std::pair<int, int>, int> mp;

    std::cin >> n;

    for(int i = 0; i <= n; i++){
	std::pair<int, int> sf = make_sf_pair(i);
	mp[sf]++;
    }

    long long ans = 0;

    for(int i = 0; i <= n; i++){
	std::pair<int, int> sf = make_sf_pair(i);
	std::pair<int, int> fs = std::make_pair(sf.second, sf.first);

	ans += mp[fs];
    }

    std::cout << ans << std::endl;

    return 0;
}

