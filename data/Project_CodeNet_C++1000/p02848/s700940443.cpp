#include <bits/stdc++.h>
using namespace std;


void solve(long long N, std::string S){
    for(int i = 0; i < S.size(); ++i){
        int x = S[i] - 'A';
        x = (x + N) % 26;
        cout << (char)(x + 'A');
    }
    cout << endl;
    return;
}

int main(){
    long long N;
    scanf("%lld",&N);
    std::string S;
    std::cin >> S;
    solve(N, S);
    return 0;
}
