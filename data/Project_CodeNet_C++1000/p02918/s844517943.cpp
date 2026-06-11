#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(long long N, long long K, std::string S){
    int score = 0;
    for(int i = 0; i < N - 1; ++i){
        if(S[i] == S[i+1]) score++;
    }
    int ans = min(score+2*K, N-1);
    cout << ans << endl;
}

int main(){
    long long N;
    scanf("%lld",&N);
    long long K;
    scanf("%lld",&K);
    std::string S;
    std::cin >> S;
    solve(N, K, S);
    return 0;
}
