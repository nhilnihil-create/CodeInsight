#include <iostream>
#include <vector>
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
    string A,B="ABC";
        cin >> A;
        if (A == B) {
            cout << "ARC";
        }
        else {
            cout << "ABC";
        }
}
