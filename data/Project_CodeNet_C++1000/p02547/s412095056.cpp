#include <iostream>
#include <vector>

int main () {

    int n;
    std::cin >> n;
    std::vector< std::pair<int, int> > d(n);
    for(int i = 0; i < n; i++) std::cin >> d.at(i).first >> d.at(i).second;

    bool ans = false;
    for(int i = 1; i < n - 1; i++) {
        if(d.at(i - 1).first == d.at(i - 1).second
        && d.at(i).first == d.at(i).second
        && d.at(i + 1).first == d.at(i + 1).second) ans = true;
    }

    if(ans) std::cout << "Yes" << std::endl;
    else std::cout << "No" << std::endl;

    return 0;
}