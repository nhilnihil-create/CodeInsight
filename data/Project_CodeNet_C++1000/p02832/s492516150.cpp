#include<bits/stdc++.h>
using namespace std;

int main() {
    long long N;
    cin >> N;
    vector <long long> a(N);
    for (long long i=0; i<N; i++) cin >> a.at(i);
    long long cnt=1;
    long long ans=0;
    for (long long i=0; i<N; i++) {
        if (cnt!=a.at(i)) ans++;
        else cnt++;
    }
    if (cnt==1) cout << "-1\n";
    else cout << ans << endl;
}