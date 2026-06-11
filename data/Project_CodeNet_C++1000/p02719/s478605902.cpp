#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int N, K;
    cin >> N >> K;
    long long int ans;
    ans=N%K;
    ans=min(ans,K-ans);

    cout << ans << endl;
}