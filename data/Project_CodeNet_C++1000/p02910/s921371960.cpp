#include <bits/stdc++.h>
using namespace std;

const string YES = "Yes";
const string NO = "No";

void solve(std::string S){
    for(int i = 1; i < S.size()+1; ++i){
        if(i % 2 == 0){
            if(S[i-1] == 'R'){
                cout << NO << endl;
                return;
            }
        }else{
            if(S[i-1] == 'L'){
                cout << NO << endl;
                return;
            }
        }
    }
    cout << YES << endl;
}

int main(){
    std::string S;
    std::cin >> S;
    solve(S);
    return 0;
}
