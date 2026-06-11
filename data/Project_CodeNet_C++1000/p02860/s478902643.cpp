#include <bits/stdc++.h>
using namespace std;

const string YES = "Yes";
const string NO = "No";

void solve(long long N, std::string S){
    if(N%2 == 0){
        //cout << S.substr(0, S.size()/2) << endl;
        //cout << S.substr(S.size()/2-1, S.size()/2) << endl;
        if(S.substr(0, S.size()/2) == S.substr(S.size()/2, S.size()/2)) cout << YES << endl;
        else cout << NO << endl;
    }else cout << NO << endl;
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
