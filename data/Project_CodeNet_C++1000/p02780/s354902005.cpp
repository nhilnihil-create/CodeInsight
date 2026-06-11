
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

void Main() {
    // input
    u_int32_t N, K;
    cin >> N >> K;

    double S[N+1];
    S[0] = 0;
    for (u_int32_t i = 1; i <= N; i++) {
        u_int32_t p;
        cin >> p;
        // cout << "p: " << p << endl;
        S[i] = S[i-1] + (1.0 + p)/2; 
        // cout << "S: "<< S[i] << endl;
    }

    vector<double> diff(N-K+1);
    for (u_int32_t i = 0; i + K <= N; i++) {
        diff[i] = S[i+K] - S[i];
        // cout << "d: " << diff[i] << endl;
    }

    sort(diff.begin(), diff.end(), greater<double>());

    // output
    cout << diff[0] << endl;

}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
