#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int N; cin >> N;
    vector<int> A(N);
    for(int i=0; i < N; i++){
        cin >> A[i];
    }
    
    map<int, int> cnt;
    long long ans=0;

    for(int i=0; i<N; i++){
        int sa = i - A[i];
        ans += cnt[sa];
        int wa = i + A[i];
        cnt[wa]++;
    }

    cout << ans << endl;
}