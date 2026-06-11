#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <map>
#include <queue>

int main(){
    int n, m;
    std::cin >> n >> m;

    std::priority_queue<int> pq;
    for (int i = 0; i < n; i++)
    {
        int a;
        std::cin >> a;
        pq.push(a);
    }
    for (int i = 0; i < m; i++)
    {
        int b = pq.top();
        pq.pop();
        pq.push(b / 2);
    }
    unsigned long long int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += pq.top();
        pq.pop();
    }
    
    std::cout << ans << std::endl;

    return 0;
}