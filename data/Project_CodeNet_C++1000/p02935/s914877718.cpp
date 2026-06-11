#include <iostream>
#include <iomanip>
#include <queue>

int main() {
    int n; std::cin >> n;
    std::priority_queue<double, std::vector<double>, std::greater<double>> q;
    for (int i = 0; i < n; i++) {
        double a; std::cin >> a;
        q.push(a);
    }

    while(q.size() > 1) {
        auto a = q.top(); q.pop();
        auto b = q.top(); q.pop();
        q.push((a+b)/2);
    }
    std::cout << std::fixed << std::setprecision(15) << q.top() << std::endl;
    return 0;
}