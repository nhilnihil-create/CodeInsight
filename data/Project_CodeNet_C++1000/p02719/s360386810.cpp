#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N,K; cin >> N >> K;
    long long r=N%K;
    long long ans=min(r,(abs(r-K)));
    cout << ans << endl;
}
