#include<iostream>
#include<algorithm>
#include<vector>

const static int YEAR = 2019;

int main(void){
    std::string s;
    std::cin >> s;
    std::reverse(s.begin(), s.end());

    std::vector<int> cnt(3000);
    int tot = 0;
    int keta = 1;
    int ans = 0;

    for(int i = 0; i < s.size(); i++){
	cnt[tot]++;
	tot += (s[i] - '0') * keta;
	tot = tot % YEAR;
	// std::cout << tot << std::endl;
	ans += cnt[tot];
	keta = keta * 10 % YEAR;
    }
    std::cout << ans << std::endl;
    return 0;
}

