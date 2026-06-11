#include <bits/stdc++.h>
using namespace std;


void solve(long long N, std::string S){
    long long ans = 0;
    for(int i = 0; i < N-1; ++i){
        if(S[i] != S[i+1]) ans++;
    }
    cout << ans + 1 << endl;
}

int main(){
    long long N;
    scanf("%lld",&N);
    std::string S;
    std::cin >> S;
    solve(N, S);
    return 0;
}
