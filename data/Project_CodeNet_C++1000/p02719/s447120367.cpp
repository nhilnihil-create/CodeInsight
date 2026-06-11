#include <bits/stdc++.h>
using namespace std;

int main(){
    long long N,K;
    cin >> N >> K;
    long long ans = min(N%K,K-N%K);
    cout << ans << endl;
}