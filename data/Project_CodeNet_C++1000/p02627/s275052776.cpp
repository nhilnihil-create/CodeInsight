#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define rep(i,n) for(int i = 0; i , (n); ++i)
using ll = long long;
using namespace std;
int sum(int n) {
    if (n == 0) {
        return 0;
    }

    int s = sum(n - 1);
    return s + n;
}
int main() {
    char s;
    cin >> s;

    if (isupper(s))
    {
        cout << "A" << endl;
    }
    else
    {
        cout << "a" << endl;
    }

    return 0;
}
