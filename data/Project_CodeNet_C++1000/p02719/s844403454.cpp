#include <iostream>
#include <math.h>
using namespace std;

long long N, K;

long long res;

int main(){
    cin >> N >> K;
    if (N >= K)
    {
        res = min(N - K * (N / K), abs(N - K * (N / K + 1)));
    }
    else{
        res = min(N, abs(N - K));
    }
    cout << res << endl;

}