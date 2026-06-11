#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    string l;
    cin >> l;
    ll dp[2];
    dp[0] = 0;
    dp[1] = 1;
    for(int i = 0; i < l.size(); i++){
        if(l[i] == '1'){
            dp[0] = (dp[0]*3+dp[1])%1000000007;
            dp[1] = (dp[1]*2)%1000000007;
        }
        else{
            dp[0] *= 3;
            dp[0] %= 1000000007;
        }
    }
    cout << (dp[0] + dp[1])%1000000007 << endl;
}