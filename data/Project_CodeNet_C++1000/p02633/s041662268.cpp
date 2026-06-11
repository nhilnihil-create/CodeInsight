//過去問演習はここ
//問題名：Remainder Reminder
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long GCD(long long A, long long B) {
    if (B == 0) return A;
    else return GCD(B, A % B);
}
int main() {
    long long N; cin >> N;
    long long gcd = GCD(N, 360);
    long long LCM = N * 360 / gcd;
    cout << LCM / N << endl;
}