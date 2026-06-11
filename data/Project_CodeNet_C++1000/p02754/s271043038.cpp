#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    long long n, a, b;
    cin >> n >> a >> b;

    long long c = n / (a + b);
    long long d = n - c * (a + b);

    cout << c * a + min(a, d) << endl;

}