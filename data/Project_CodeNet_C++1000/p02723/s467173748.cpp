#include <bits/stdc++.h>
using namespace std;

const string YES = "Yes";
const string NO = "No";

void solve(std::string S){
    if(S[2] == S[3] && S[4] == S[5]){
        cout << YES << endl;
    }
    else cout << NO << endl;
    return;
}

int main(){
    std::string S;
    std::cin >> S;
    solve(S);
    return 0;
}
