#include <bits/stdc++.h>
using namespace std;


void solve(long long N, std::string S, std::string T){
    for(int i = 0; i < N; ++i){
        cout << S[i] << T[i];
    }
    cout << endl;
    return;
}

int main(){
    long long N;
    scanf("%lld",&N);
    std::string S;
    std::cin >> S;
    std::string T;
    std::cin >> T;
    solve(N, S, T);
    return 0;
}
