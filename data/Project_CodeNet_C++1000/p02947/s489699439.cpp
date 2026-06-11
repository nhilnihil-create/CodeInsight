#include<iostream>
#include<vector>
#include<map>

int main(void){
    std::vector<long long > a(26);
    long long n;
    std::cin >> n;
    std::map<std::vector<long long >, long long> mp;
    for(int i = 0; i < n; i++){
        std::string s;
        std::cin >> s;
        for(int j = 0; j < 10; j++){
            long long cur = s[j] - 'a';
            a[cur]++;
        }
        mp[a]++;
        for(int j = 0; j < 26; j++){
            a[j] = 0;
        }
    }
    long long ans = 0;
    for(auto i = mp.begin(); i != mp.end(); i++){
            ans += (i->second) * (i->second - 1) / 2;
    }
    std::cout << ans << std::endl;
    return 0;
}