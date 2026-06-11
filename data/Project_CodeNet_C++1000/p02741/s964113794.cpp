#include<iostream>

using namespace std;

int main() {
    static int NUMS[] = { 0, 1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51 };

    int index;
    cin >> index;
    cout << NUMS[index] << endl;

    return 0;
}