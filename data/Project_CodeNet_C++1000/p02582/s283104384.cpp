#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int solve(string S){
    int max_global = 0;
    int max_current = 0;
    for (int i = 0; i < S.size(); ++i) {
        if(S[i] == 'R'){
            max_current++;
            max_global = max(max_global,max_current);
        }else{
            max_global = max(max_global,max_current);
            max_current = 0;
        }
    }
    return max_global;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    //freopen("../input.txt","r",stdin);

    string S;
    cin >> S;

    cout << solve(S);
}
