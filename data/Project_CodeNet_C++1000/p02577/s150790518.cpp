#include <iostream>

using namespace std;

int main()
{
    string n;
    int sum;
    cin >> n;
    for (char c : n) {
        sum += int(c) - 48;
    }
    if (sum % 9 == 0) {
        cout << "Yes";
    }
    else {
        cout << "No";
    }
}