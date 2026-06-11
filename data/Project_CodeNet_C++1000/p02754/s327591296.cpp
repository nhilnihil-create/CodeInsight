#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <math.h> // sqrt
using namespace std;

int main() {
    long long N, A, B;
    cin >> N >> A >> B;
    if (A == 0) {
        cout << 0 << endl;
        return 0;
    }
    long long last = N % (A + B);
    long long ans = (N / (A + B)) * A;
    if (last < A) {
        ans += last;
    }
    else {
        ans += A;
    }
    cout << ans << endl;
}