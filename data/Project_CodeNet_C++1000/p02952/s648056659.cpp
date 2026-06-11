#include <iostream>
using namespace std;
int ketasuu(int n) {
    if (n == 0) {
        return 1;
    }
    int sisuu=1, result=0;
    while (n/sisuu != 0) {
        sisuu *= 10;
        result++;
    }
    return result;
}
int nketaNum(int n) {
    int k=1;
    for (int i=0; i<n-1; i++) {
        k *= 10;
    }
    return 9*k;
}
int main() {
    int n;
    cin >> n;
    int result = 0;
    if (ketasuu(n)%2 == 0) {
        for (int i=1; i<ketasuu(n); i+=2) {
            result += nketaNum(i);
        }
    } else {
        result = n;
        for (int i=2; i<ketasuu(n); i+=2) {
            result -= nketaNum(i);
        }
    }
    cout << result << endl;
}