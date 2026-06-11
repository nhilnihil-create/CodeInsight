#include <iostream>
#include <algorithm>
#include <vector>

int main(){
    int n, m;
    std::string s;
    std::cin >> n >> m >> s;
    std::reverse(s.begin(), s.end());
    int now = 0;
    std::vector<int> vec;
    while(1){
        if(now+m >= n){
            vec.push_back(n-now);
            break;
        }
        int prog = m;
        while(s[now+prog] - '0'){
            prog--;
            if(prog <= 0){
                std::cout << -1 << std::endl;
                return 0;
            }
        }
        vec.push_back(prog);
        now += prog;
    }
    std::reverse(vec.begin(), vec.end());
    for(int i : vec){
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}
