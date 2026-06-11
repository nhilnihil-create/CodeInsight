#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i,n) for (int i = 0; i < (n); ++i)


void solve(long long K, std::string S){
    int len = S.size();
    string ans = "";
    if(len <= K) ans = S;
    else {
        rep(i,K) ans += S[i];
        ans += "...";
    }

    cout << ans << endl;
}

int main(){
    long long K;
    scanf("%lld",&K);
    std::string S;
    std::cin >> S;
    solve(K, S);
    return 0;
}
