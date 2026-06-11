#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
    long N;
    cin >> N;
    long ans = (N / 500) * 1000 + ((N % 500) / 5) * 5;
    cout << ans << endl;
}
