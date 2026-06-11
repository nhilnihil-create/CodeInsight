#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>



int main () {
    int a, b, c;
    std::cin >> a >> b >> c;

    std::vector<int> di;
    di.push_back(a + b);
    di.push_back(b + c);
    di.push_back(c + a);

    std::cout << *std::min_element(di.begin(), di.end()) << "\n";
}