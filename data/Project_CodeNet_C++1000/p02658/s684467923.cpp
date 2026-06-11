#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
using Bint = boost::multiprecision::cpp_int;
using namespace std;
typedef long long ll;
typedef pair<int, ll> Pil;

int N;
const int MAX_N = 1.0e5 + 10;
Bint A[MAX_N];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];

    bool is_over = false;
    Bint mul_A = 1;
    for (int i = 0; i < N; i++) {
        if (A[i] == 0) {
            is_over = false;
            mul_A = 0;
            break;
        }
    }

    if (mul_A != 0) {
        for (int i = 0; i < N; i++) {
            mul_A *= A[i];
            if (mul_A > (Bint)1.0e18) {
                is_over = true;
                break;
            }
        }
    }

    cout << (is_over ? -1 : mul_A) << endl;

    
    return 0; 
}