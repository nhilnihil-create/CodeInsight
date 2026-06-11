#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define xrep(i, a, b) for (int i = int(a); i < int(b); ++i)
using ll = long long;

int a, b;
int X;

void search(int A, int B) {
    if(pow(A,5) > X ) {
        A = B;
        search(A,B-1);
        return;
    }
    if(pow(A,5)-pow(B,5) == X) {
        a = A;
        b = B;
        return;
    }
    search(A+1, B);
}

int main() {
    cin >> X;
    search(-100, 100);
    cout << a << " " << b << endl;

    return 0;
}