#include <iostream>
#include <iomanip>
#include <queue>
#include <vector>

int main() {
    int n;
    
    std::priority_queue<double, std::vector<double>, std::greater<double> > q;

    std::cin >> n;
    for (int i = 0; i < n; i++) {
        int v;
        std::cin >> v;
        q.push((double) v);
    }

    while (q.size() > 1) {
        double a, b;
        a = q.top();
        q.pop();
        b = q.top();
        q.pop();

        q.push((a + b) / 2);
    }

    double r = q.top();
    std::cout << std::setprecision(5) << r << std::endl;
}