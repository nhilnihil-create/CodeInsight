#include<bits/stdc++.h>
using namespace std;

int main(){
    long long N, K, ans;
    cin >> N >> K;
    if(N - (N/K)*K > abs(N - (N/K+1)*K)) ans = abs(N - (N/K+1)*K);
    else ans = N - (N/K)*K;
    cout << ans << endl;
    return 0;
}