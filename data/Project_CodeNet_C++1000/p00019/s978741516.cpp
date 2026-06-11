#include <iostream>

using namespace std;

int main() {
    long long answer = 1;
    int n;
    cin >> n;

    for (int i = n; i != 0; i--) {
            answer *= i;
    }
cout << answer << endl;
return 0;
}