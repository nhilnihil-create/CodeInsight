#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long gcd(long long x, long long y){
    if(x < y) swap(x, y);
    if(x % y == 0) return y;
    return gcd(y, x % y);
}
long long lcm(long long x, long long y){
    long long g = gcd(x, y);
    return x / g * y;
}
int main(){
    long long N, M;
    cin >> N >> M;
    vector<long long> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
        A[i] /= 2;
    }
    long long l = A[0];
    for(int i = 0; i < N; i++){
        l = lcm(l, A[i]);
        if(l > M){
            cout << 0 << endl;
            return 0;
        }
    }
    for(int i = 0; i < N; i++){
        long long t = l / A[i];
        if(t % 2 == 0){
            cout << 0 << endl;
            return 0;
        }
    }
    long long cnt = M / l;
    cout << (cnt + 1) / 2 << endl;
}