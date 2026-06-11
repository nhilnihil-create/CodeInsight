#include <iostream>
#include <vector>
using namespace std;
vector<size_t> creatVec(size_t size);
int main() {
    size_t size{}, ans{};
    cin >> size;
    vector<size_t> nums {creatVec(size)};
    for (size_t i{}; i < size; i+=2) if (nums[i] % 2 != 0) ans++;
    cout << ans;
    return 0;
}
vector<size_t> creatVec(size_t size) {
    vector<size_t> vec {};
    for (size_t i{}; i < size; i++) {
        size_t in{};
        cin >> in;
        vec.push_back(in);
    }
    return vec;
}