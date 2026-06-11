#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i,n) for (int i = 0; i < (n); ++i)


void solve(std::string S){
    ll ans = 0;
    ll j = S.size() - 1;
    rep(i,S.size()){
        if(S[i] != S[j]) ans++;
        j--;
    }
    cout << ans/2 << endl;

}

int main(){
    std::string S;
    std::cin >> S;
    solve(S);
    return 0;
}
