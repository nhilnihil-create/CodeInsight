#include<bits/stdc++.h>
using namespace std;

int main() {
    int N, K, ans=0;
    cin >> N >> K;
    vector<int> A(N);
    for(int i=1;i<=N;i++) {
        cin >> A[i];
        if(A[i]>=K) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
