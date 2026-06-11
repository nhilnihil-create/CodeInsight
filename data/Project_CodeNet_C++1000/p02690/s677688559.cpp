#include <bits/stdc++.h>


using namespace std;


int main(void) {
    map<long long, long long> res;
    for (long long i = 0; i < 1000; i++) {
        long long t = i * i * i * i * i;
        res[i] = t;
    }
    for (long long i = -1; i > -1000; i--) {
        long long t = i * i * i * i * i;
        res[i] = t;
    }

    long long X;
    cin >> X;
    long long A, B;
    for (auto pa : res) {
        for (auto pb : res) {
            if (pa.second - pb.second == X) {
                A = pa.first;
                B = pb.first;
            }
        }
    }
    cout << A << " " << B << endl;
}
