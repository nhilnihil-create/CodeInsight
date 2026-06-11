#include <iostream>
#include <vector>
using namespace std;
using ll = long long int;
int main() {
    ll N;
    cin >> N;

    vector<ll> B(N);
    for (size_t i = 0; i < N - 1; i++)
    {
        cin >> B[i];
    }

    ll sum = 0;
    for (size_t i = 0; i < N; i++)
    {
        if (i == N - 1) {
            sum += B[i - 1];
        } else if (i == 0) {
            sum += B[i];
        } else {
            sum += min(B[i - 1], B[i]);
        }
    }
    cout << sum << endl;
}