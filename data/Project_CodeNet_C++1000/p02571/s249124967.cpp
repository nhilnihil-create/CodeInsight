#include<iostream>
#include<string>

int main(){
        std::string S, T;
        std::cin >> S >> T;
        int count = 0;
        int _min = T.size();
        int _limit = S.size() - T.size();
        for (int i = 0; i < _limit+1; i++) {
            count = 0;
            std::string R = S.substr(i, T.size());
            for (int j = 0; j < T.size(); j++) {
                if (R[j] != T[j]) {
                    count += 1;
                }
            }
            if (count < _min) {
                _min = count;
            }
        }
        std::cout << _min << std::endl;
    return 0;
}