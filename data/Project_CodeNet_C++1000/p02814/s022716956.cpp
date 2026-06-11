#include<bits/stdc++.h>
using namespace std;

long long gcd(long long x, long long y){
    if(y == 0) return x;
    else return gcd(y, x % y);
}

int main() {
    long long N, M; cin >> N >> M;
    long long A[N];
    long long even = 0;
    bool dif = false;
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
        if(i > 0){
            long long a = max(A[i], A[i-1]), b = min(A[i], A[i-1]);
            if(a % b == 0 && (a / b) % 2 == 0) dif = true;
        }
    }

    if(dif){
        cout << "0" << endl;
        return 0;
    }

    for (int i = 0; i < N; i++)
    {
        A[i] /= 2;
    }


    long long lcm = 1;
    for (int i = 0; i < N; i++)
    {
        lcm = A[i] / gcd(A[i], lcm) * lcm;
    }

    long long ans = M / lcm;
    ans = (ans + 1) / 2;
    cout << ans << endl;
}