#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    long long int a, b, c, d;
    vector<long long int> res;
    ios::sync_with_stdio(false);
    
    cin >> a >> b >> c >> d;

    res.push_back(a * c);
    res.push_back(b * d);
    res.push_back(b * c);
    res.push_back(a * d);

    auto max = max_element(res.begin(), res.end());
    auto dist = distance(res.begin(), max);

    cout << res[dist];
    return 0;
}