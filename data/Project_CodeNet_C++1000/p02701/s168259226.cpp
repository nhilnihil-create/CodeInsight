#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>

int main(){
    int n;
    std::cin >> n;
    std::unordered_set<std::string> set;
    for(int i = 0; i < n; i++){
        std::string S;
        std::cin >> S;
        set.insert(S);
    }

    std::cout << set.size() << std::endl;
    return 0;
}
