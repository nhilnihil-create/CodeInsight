#include <iostream>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cmath>
#include <cstdarg>
#include <cstdlib>
#include <string>

#include <vector>
#include <tuple>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[]) {
    long long n;
    cin >> n;
    long long p = 2;
    long long ans = 0;
    long long count = 1;
    long long now = 0;
    while (n > 1) {
        if (n % p == 0) {
            n /= p;
            now ++;
            if (count == now) {
                ans ++;
                now = 0;
                count ++;
            }
        } else {
            if (p == 2) {
                p = 3;
            } else {
                p += 2;
            }
            if (p * p > n) {
                ans ++;
                break;
            } 
            count = 1;
            now = 0;
        }
    }
    cout << ans << endl;
    return 0;
}