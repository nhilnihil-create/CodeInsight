#include <iostream>
#include <vector>
using namespace std;
 
int main() {
    int N;
    cin >> N;
    long long ketasuu = 0, sum = 0;
    for (int i = 0; i < N; ++i) {
        long long d, c;
        cin >> d >> c;
        ketasuu += c;
        sum += d * c;
    }
    cout << (sum - 1) / 9 + (ketasuu - 1) << endl;
}