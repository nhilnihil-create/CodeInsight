#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const string YES = "Yes";
const string NO = "No";

void solve(long long X, long long Y){
    bool check = false;
    for(ll i = 0; i <= 100; ++i){
        for(ll j = 0; j <= 100; ++j){
            if(2*i + 4*j == Y && i + j == X) check = true;
        }
    }
    if(check){
        cout << YES << endl;
        return;
    }
    cout << NO << endl;
    return;
}

int main(){
    long long X;
    scanf("%lld",&X);
    long long Y;
    scanf("%lld",&Y);
    solve(X, Y);
    return 0;
}
