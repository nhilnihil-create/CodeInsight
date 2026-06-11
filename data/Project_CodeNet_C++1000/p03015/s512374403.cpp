#include <bits/stdc++.h>
using namespace std;
const long long int MOD = 1e9 + 7;

int main(){
    string l;
    cin >> l;
    int n = l.length();

    vector<long long int> pow3(n,1);// pow3[i] = pow(3,i)
    for(int i=1; i<n; i++){
        pow3[i] = 3 * pow3[i-1];
        pow3[i] %= MOD;
    }

    reverse(l.begin(),l.end());
    long long int ans = 1;
    for(int i=0; i<n; i++){
        if(l[i] == '1'){
            ans = pow3[i] + 2 * ans;
            ans %= MOD;
        }
    }
    cout << ans << endl;
    return 0;
}