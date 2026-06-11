#include <iostream>
#include <string>
using namespace std;

string n;
int sum;

int main() {
    cin >> n;
    for (auto x : n) {
        sum += (x - '0');
        sum %= 9;
    }
    if (sum == 0) cout << "Yes";
    else cout << "No";

}