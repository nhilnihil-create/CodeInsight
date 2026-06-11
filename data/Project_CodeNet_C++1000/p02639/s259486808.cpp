#include <iostream>
#include <vector>

int main()
{
    std::vector<int> data(5, 0);
    for(int i=0; i < 5; i++) {
        std::cin >> data[i];
    }

    for(int i=0; i < 5; i++) {
        if(data[i] == 0) {
            std::cout << i+1 << std::endl;
        }
    }
}