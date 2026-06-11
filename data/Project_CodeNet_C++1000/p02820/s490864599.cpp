#include<iostream>
#include<map>

int main(void){
    int n, k, r, s, p;
    std::string t;
    std::map<char, int> mp;
    
    std::cin >> n >> k >> r >> s >> p;
    std::cin >> t;

    for(int i = 0; i < k; i++){
	mp[t[i]]++;
    }

    for(int i = k; i < n; i++){
	if(t[i] == t[i-k]){
	    t[i] = 'x';
	}
	else mp[t[i]]++;
    }

    int ans = 0;
    ans = mp['r'] * p + mp['s'] * r + mp['p'] * s;

    std::cout << ans << std::endl;
    return 0;
}

