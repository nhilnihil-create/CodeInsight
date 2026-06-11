#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(std::string S, std::string T){
    ll ans = 0;
    for(ll i = 0; i < S.size(); ++i){
        if(S[i] != T[i]) ans++;
    }
    cout << ans << endl;
    return;
}

int main(){
    std::string S;
    std::cin >> S;
    std::string T;
    std::cin >> T;
    solve(S, T);
    return 0;
}
