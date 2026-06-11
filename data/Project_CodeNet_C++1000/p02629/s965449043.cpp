#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() {
    long long n;
    cin >> n;
    string result = "";
    int tmp = 0;
    while (n > 0) {
        n -= 1;
        tmp = n % 26;
        result += char('a' + tmp);
        n = n / 26;
    }
    reverse(result.begin(), result.end());
    cout << result << endl;
    return 0;
}