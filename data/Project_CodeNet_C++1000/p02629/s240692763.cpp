#include <bits/stdc++.h>
using namespace std;


void solve(long long N){
    string res = "";
    while (N)
    {
        --N;
        res += (char)('a' + (N % 26));
        //cout << "N:" << N << ", res:" << res << endl;
        N /= 26;
    }
    reverse(res.begin(), res.end());
    cout << res << endl;
    return;
}

int main(){
    long long N;
    scanf("%lld",&N);
    solve(N);
    return 0;
}
