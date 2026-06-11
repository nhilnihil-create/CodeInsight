#include <bits/stdc++.h>

using namespace std;

int main(){
    long long int N,ans=1;
    cin >> N;
    vector<long long int> A(N),sum(N+1,0);
    sum[0] = 3;
    for(int i=0;i<N;i++){
        cin >> A[i];
    }

    for(int i=0;i<N;i++){
        ans *= sum[A[i]];
        ans %= 1000000007;
        sum[A[i]]--;
        sum[A[i]+1]++;
    }

    cout << ans << endl;
}