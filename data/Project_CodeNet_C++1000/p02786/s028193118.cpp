#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <math.h> // sqrt
using namespace std;

long long two(long long H) {
    long long ans = 2; 
    while (true) {
        if (H < ans) {
            break;
        }
        ans *= 2;
    }
    return ans;
}

int main() {
    long long H;
    cin >> H;
    long long ans = two(H) - 1;
    cout << ans << endl;
}