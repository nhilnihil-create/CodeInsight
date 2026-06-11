#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
using ll = long long;

int main() {
    char a;

    cin >> a;

    if ('A' <= a && a <= 'Z') {
        printf("%c\n", 'A');
    }
    else {
        printf("%c\n", 'a');
    }

    return 0;
}