#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t N;
    cin >> N;
    vector<int64_t> A(N);
    int64_t S = 0;
    vector<int64_t> x(N,0);
    for ( int64_t i = 0; i < N; ++i){
        cin >> A.at(i);
        S += A.at(i);
    }
    
    int64_t r = 0;
    for ( int64_t i = 0; i < N/2; ++i){
        r += 2 * A.at(2*i+1);
    }
    x.at(0) = (S - r)/2;
    for ( int64_t i = 1; i < N; ++i){
        x.at(i) = A.at(i-1) - x.at(i-1);
    }
    
    for ( int64_t i = 0; i < N; ++i){
        cout << 2 * x.at(i) << " ";
    }
    cout << endl;
    
    
    return 0;
}

