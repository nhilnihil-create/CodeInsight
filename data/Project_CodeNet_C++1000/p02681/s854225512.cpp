#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i,n) for (int i = 0; i < (n); ++i)

const string YES = "Yes";
const string NO = "No";

void solve(std::string S, std::string T){
    bool isOk = true;
    rep(i,T.size()-1){
        if(S[i] != T[i]) isOk = false;
    }
    if(isOk) cout << YES << endl;
    else cout << NO << endl;
}


int main(){
    std::string S;
    std::cin >> S;
    std::string T;
    std::cin >> T;
    solve(S, T);
    return 0;
}
