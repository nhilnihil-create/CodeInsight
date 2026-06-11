#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

#define F first
#define S second
#define PB push_back
#define MP make_pair

#define FOR_EX(i, a, b) for (int i = a; i < b; i++)
#define FOR_IN(i, a, b) for (int i = a; i <= b; i++)

#define ALL(a) a.begin(), a.end()

// g++ -std=c++17 -O2 -Wall template.cpp -o template
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // Solution

    int n;
    cin >> n;
    int a[n];
    FOR_EX(i, 0, n) {
        cin >> a[i];
    }
    // Only works if split by exactly half
    // long long t = 0;
    // FOR_EX(i, 0, n / 2) {
    //     int left = a[i];
    //     int right = a[n - i - 1];
    //     t += (right - left);
    // }
    // cout << (n % 2 == 0 ? abs(t) : abs(abs(t) - a[n / 2])) << endl;
    int i = 0, j = n - 1;
    long long left = 0;
    long long right = 0;
    while (i <= j) {
        if (left < right) {
            left += a[i++];
        } else {
            right += a[j--];
        }
    }
    cout << abs(left - right) << endl;
}
