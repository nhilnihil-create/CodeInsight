#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void creatVec(vector<size_t> &vec, int size);
int main() {
    size_t fruit{}, choosen{}, sum{};
    cin >> fruit >> choosen;
    vector<size_t> prices{};
    creatVec(prices, fruit);
    sort(prices.begin(), prices.end());
    for (size_t i{}; i < choosen; i++) sum += prices[i];
    cout << sum;
}
void creatVec(vector<size_t> &vec, int size) {
    for (int i{}; i < size; i++) {
        int in{};
        cin >> in;
        vec.push_back(in);
    }
}