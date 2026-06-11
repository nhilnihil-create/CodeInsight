#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, p; string s;
    cin >> n >> p >> s;
    
    vector<int> d(n+1);
    for(int i=0; i<n; i++){
        d[i] = s[i] - '0';
    }
    reverse(d.begin(), d.end());

    if(p == 2 || p == 5){
        long long int ans = 0;
        for(int i=1; i<=n; i++){
            //cout << d[i] << " ";
            if(d[i] % p == 0) ans += (n-i+1);
        }
        cout << ans << endl;
        return 0;
    }

    map<int, long long int> rem;
    rem[0] = 1;
    int pow10 = 1;
    // cumulative sum
    for(int i=1; i<=n; i++){
        d[i] = (d[i] * pow10 + d[i-1]) % p;

        if(rem.find(d[i]) == rem.end()) rem[d[i]] = 1;
        else rem[d[i]] += 1;

        pow10 *= 10;
        pow10 %= p;
    }
    
    long long int ans = 0;
    for(auto r : rem){
        //cout << r.first << " " << r.second << endl;
        ans += r.second * (r.second - 1) / 2;
    }
    cout << ans << endl;
    return 0;
}