#include<bits/stdc++.h>
using namespace std;



int main(void) {
    int X, Y, A, B, C;
    cin >> X >> Y >> A >> B >> C;

    long long p[100010] = {0};
    long long q[100010] = {0};
    long long r[100010] = {0};
    for (int i=0; i<A; i++) cin >> p[i];
    for (int i=0; i<B; i++) cin >> q[i];
    for (int i=0; i<C; i++) cin >> r[i];

    sort(p, p+A, greater<>());
    sort(q, q+B, greater<>());
    sort(r, r+C, greater<>());

    long long z[300030] = {0};
    for (int i=0; i<X; i++) {
        z[i] = p[i];
    }
    for (int i=0; i<Y; i++) {
        z[i+X] = q[i];
    }
    for (long long i=0; i<C; i++) {
        z[i+X+Y] = r[i];
    }
    sort(z, z+300030, greater<>());
    long long sum = 0;
    for (long long i=0; i<(X+Y); i++) {
        sum += z[i];
    }
    cout << sum << endl;

    return 0;
}