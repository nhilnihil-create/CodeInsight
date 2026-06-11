#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long long n, k, ans=0; cin >> n >> k;
    long long ac[n+1]; ac[0] = 0;
    map<long long, long long> freq;
    freq[0] = 1;
    for (int i=1; i<=n; i++){
        if (i >= k) freq[(ac[i-k] - i + k)%k]--;
        cin >> ac[i];
        if (k == 1 && ac[i]%k == 1) ans++;
        ac[i] += ac[i-1];
        ans += freq[(ac[i] - i)%k]++;
    }
    cout << ans << endl;
}