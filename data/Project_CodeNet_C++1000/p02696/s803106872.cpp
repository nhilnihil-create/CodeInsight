#include<bits/stdc++.h>
#include<boost/dynamic_bitset.hpp>
using namespace std;
using u64 = uint64_t;
using s64 = int64_t;

int main(void) {
    u64 A, B, N;
    cin >> A >> B >> N;

    if(B > N) {
        cout << A * N / B << endl; 
    }  else {
        cout << A * (B - 1) / B;
    }

    return 0;
}