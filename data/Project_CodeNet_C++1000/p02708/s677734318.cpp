#include <bits/stdc++.h>
using namespace std;
const long long M = 7ll + (long long) 1e9;

int main(){
    long long N, K;
    cin >> N >> K;

    long long ans=0;

    for(long long k=K; k<=N+1; k++){
        ans += ( k*N - (k-1)*k + 1 )%M;
        ans %= M;
    }

    cout << ans << endl;

    return 0;
}