#include<iostream>
#include<vector>
#include<algorithm>

int main(void){
    std::string s, t;
    std::cin >> s >> t;
    std::vector<std::vector<int>> a(26);
    for(int i = 0; i < s.size(); i++){
        a[s[i] - 'a'].push_back(i);
    }
    int p = -1;
    long long ans = 0;
    for(int i = 0; i < t.size(); i++){
        int cur = t[i] - 'a';
        if(a[cur].size() == 0){
            std::cout << -1 << std::endl;
            return 0;
        }
        while(1){
            auto j = std::upper_bound(a[cur].begin(), a[cur].end(), p);
            if(j != a[cur].end()){
               ans += *j - p;
               p = *j;
               break;
               // std::cout << ans << std::endl;
           }else{
               ans += s.size() - p - 1;
               p = -1;
           }
        }
    }
    std::cout << ans << std::endl;
    return 0;
}