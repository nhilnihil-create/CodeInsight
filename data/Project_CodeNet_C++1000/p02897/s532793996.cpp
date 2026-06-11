#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, od;
    cin >> n;
    od = n / 2;
    if(n % 2 != 0) {
        od++;
    }
    printf("%f\n", od / (double) n);
}
