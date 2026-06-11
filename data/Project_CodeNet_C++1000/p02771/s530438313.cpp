#include <iostream>
#include <map>

int a, b, c;

int main() {
    std::cin >> a >> b >> c;
    std::map<int,int> cnts;
    cnts[a]++;
    cnts[b]++;
    cnts[c]++;
    if (cnts.size() == 2){
        std::cout << "Yes";
    } else {
        std::cout << "No";
    }
}