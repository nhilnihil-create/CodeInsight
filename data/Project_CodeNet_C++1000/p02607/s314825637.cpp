#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    int a[N];
    int cnt=0;
    for (int i=0;i<N;++i) cin >> a[i];
    for (int i=1;i<=N;++i) {
        if (i % 2 == 1 && a[i-1] % 2 == 1) cnt++;
    }
    cout << cnt << endl;
}