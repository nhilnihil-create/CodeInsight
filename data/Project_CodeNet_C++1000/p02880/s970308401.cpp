#include <bits/stdc++.h>
using namespace std;

const string YES = "Yes";
const string NO = "No";

void solve(long long N){
    for(int i = 1; i <= 9; ++i){
        for(int j = 1; j <= 9; ++j){
            if(N == i * j){
                cout << YES << endl;
                return;
            }
        }
    }
    cout << NO << endl;
    return;
}

int main(){
    long long N;
    scanf("%lld",&N);
    solve(N);
    return 0;
}
