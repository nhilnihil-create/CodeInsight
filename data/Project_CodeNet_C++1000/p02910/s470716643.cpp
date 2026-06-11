#include<iostream>
#include<set>

int main(void){
    std::string s;
    std::cin >> s;
    std::set<char> odd = {'R', 'U', 'D'};
    std::set<char> even = {'L', 'U', 'D'};
    int size = s.size();
    for(int i = 0; i < size; i++){
        int cur = i + 1;
        if(cur % 2 == 0 && even.find(s[i]) == even.end()){
            std::cout << "No" << std::endl;
            return 0;
        }else if(cur % 2 == 1 && odd.find(s[i]) == odd.end()){
            std::cout << "No" << std::endl;
            return 0;
        }
    }
    std::cout << "Yes" << std::endl;
    return 0;
}