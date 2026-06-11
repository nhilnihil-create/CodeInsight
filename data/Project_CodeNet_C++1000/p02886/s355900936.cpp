
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 51;
int n;
int d[N];
int psum[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> d[i];
        sum += d[i];
        psum[i] = sum;
    }
    int res = 0;
    for (int i = 0; i < n; ++i) {
        res += d[i] * (sum - psum[i]);
    }
    cout << res << endl;


    return 0;
}

