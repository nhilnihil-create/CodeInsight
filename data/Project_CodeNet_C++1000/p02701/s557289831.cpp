#include <iostream>
#include <unordered_set>
#include <string>

int main() {
    int N;
    std::cin >> N;
    std::unordered_set<std::string> a;
    for (int i=0; i<N; i++) {
        std::string s;
        std::cin >> s;
        a.insert(s);
    }
    std::cout << a.size() << std::endl;
}