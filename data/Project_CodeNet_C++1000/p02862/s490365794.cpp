#include <bits/stdc++.h>
using namespace std;

static const long M = 1000000007;

long p[2000000];

void getp(){
    p[0] = 1;
    for(int i = 1; i <= 2000000; i++)
        p[i] = i * p[i - 1] % M;
    return;
}

long power(long n, long m){
    long ans = 1;
    if(m > 0){
        ans = power(n, m / 2);
        if(m % 2 == 0) ans = (ans * ans) % M;
        else ans = (((ans * ans) % M) * n) % M;
    }
    return ans;
}

int main(){
    long X, Y;
    cin >> X >> Y;
    if((X + Y) % 3 != 0) cout << 0 << endl;
    else{
        long d = (X + Y) / 3;
        if(X < d || Y < d) cout << 0 << endl;
        else{
            getp();
            cout << (((p[X + Y - 2 * d] * power(p[X - d], M - 2)) % M) * power(p[Y - d], M - 2)) % M << endl;
        }
    }
    return 0;
}