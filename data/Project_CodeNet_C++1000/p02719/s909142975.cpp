#include <iostream>

using namespace std;

int main(){
    long long N, K; cin >> N >> K;
    if(N > K) N = N%K;
    cout << min(N, K-N) << endl;
}