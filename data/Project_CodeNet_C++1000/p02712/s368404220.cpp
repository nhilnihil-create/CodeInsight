#include<iostream>
using namespace std;

long long sum(long long n) {
    return n * (n + 1) / 2;
}

int main() {
    int N;
    cin >> N;

    long long ans = sum(N) - sum(N/3) * 3 - sum(N/5) * 5 + sum(N/15) * 15;
    cout << ans << endl;

}