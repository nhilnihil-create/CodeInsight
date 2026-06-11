#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e15;

#include <math.h>
#define PI 3.14159265358979323846264338327950L
const int mxN = 1e9 + 7;


int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int s1 = a[0];
    int s2 = a[n - 1];
    int i = 1;
    int j = n - 2;
    while (i <= j) {
        if (s1 > s2) {
            while (i <= j && s1 > s2) {
                s2 += a[j];
                j--;
            }
        }
        else {
            while (i <= j && s1 <= s2) {
                s1 += a[i];
                i++;
            }
        }
    }
    cout << abs(s1 - s2);
    return 0;
}