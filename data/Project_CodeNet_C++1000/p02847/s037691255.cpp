#include <iostream>
using namespace std;

int find(const std::string *v, std::string val) {
    for(int i = 0; i < 7; i++) {
        if(v[i] == val) {
            return i;
        }
    }
    return -1;
}

int main(void) {
    std::string week[7] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};

    char str[3];
    std::cin >> str;

    int res = 7 - find(week, str);
    
    std::cout << res << std::endl;
    return 0;
}