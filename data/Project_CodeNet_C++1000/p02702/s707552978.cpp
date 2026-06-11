#include <bits/stdc++.h>
using namespace std;
#define int long long

int mod_pow(int n, int e, int mod){
    int ans = 1;
    n = n % mod;
    while(e != 0){
        if(e % 2 == 1){
            ans = (ans * n) % mod;
        }
        e /= 2;
        n = (n * n) % mod;
    }
    return ans;
}

signed main(){
    // cout << fixed << setprecision(10) << flush;

    string s;
    cin >> s;

    vector<int> rem(s.size(), 0);
    int pow_ten = 1;
    for(int i=s.size()-1; i>=0; i--){
        rem[i] = ((s[i] - '0') * pow_ten) % 2019;
        pow_ten = (pow_ten * 10) % 2019;
    }    
    
    for(int i=1; i<s.size(); i++){
        rem[i] = (rem[i] + rem[i-1]) % 2019;
    }

    vector<int> num(2019, 0);
    num[0] = 1;
    for(int i=0; i<s.size(); i++){
        num[rem[i]]++;
    }

    int ans = 0;
    for(int i=0; i<num.size(); i++){
        ans += (num[i]-1)*num[i]/2;
    }
    cout << ans << endl;

    return 0;
}