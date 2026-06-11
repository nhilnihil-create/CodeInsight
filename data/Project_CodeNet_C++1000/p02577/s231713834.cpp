#include <iostream>
#include <algorithm>
#include<vector>
#include<string>
using namespace std;
using ll = long long;

int main() {
    std::string N;
    cin >> N;
    size_t size = N.length();
    int sum=0;
    for (int i = 0; i < size; i++) {
        sum += N[i] - '0';
    }
        if (sum % 9 == 0) {
            cout << "Yes";

        }
        else {
            cout << "No";

        }
}