#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>

const int length = 10;

int main(){
    int n;
    std::cin >> n;
    long long cnt = 0;
    std::map<std::string, long long> mp;
    for(int i = 0; i < n; i++){
        std::string S;
        std::cin >> S;
        std::sort(S.begin(), S.end());
        mp[S]++;
    }

    for(auto m : mp){
        cnt += m.second * (m.second - 1) / 2;
    }

    std::cout << cnt << std::endl;
    return 0;
}
