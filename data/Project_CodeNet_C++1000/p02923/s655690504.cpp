#include<bits/stdc++.h>
using namespace std;

int main() {
    long long N;
    cin >> N;
    vector <long long> H(N);
    long long ans = 0;
    long long cnt = 0;
    cin >> H.at(0);
    for (long long i=1; i<N; i++) {
        cin >> H.at(i);
        if (H.at(i)<=H.at(i-1)) cnt++;
        else {
            ans = max(ans, cnt);
            cnt = 0;
        }
    }
    ans = max(ans, cnt);
    cout << ans << endl;
}