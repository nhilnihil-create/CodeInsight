#include <iostream>
#include <string>

int main() {
        char c;
        char t = 'a';
        for (int i = 0; i != 4; ++i) {
                std::cin >> c;
                if (c == t) {
                        std::cout << "Bad" << std::endl;
                        return 0;
                }
                t=c;
        }
        std::cout<<"Good"<<std::endl;
        return 0;
}
