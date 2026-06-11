#include <math.h>

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
int gcd(int a,int b) {
    if (a % b == 0)
        return b;
    else
        return (gcd(b, a % b));
}
int main() {

    int k,total=0;
    cin >> k;
    for (int l = 1; l <= k;l++){
        for (int m = 1; m <= k;m++){
            for (int n = 1; n <= k;n++){
                total += gcd(gcd(l, m), n);
            } }
    }
    cout << total << endl;
    return 0;
}