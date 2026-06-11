#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e5 + 7;

#include <math.h>
#define PI 3.14159265358979323846264338327950L


int main() {
    
    long long x;
    cin >> x;

    for (int i = 0; i < 1000; i++) {
        for (int j = -1000; j < 1000; j++) {
            if (pow(i, 5) - pow(j, 5) == x) {
                cout << i << " " << j;
                return 0;
            }
        }
    }
   

    return 0;
}