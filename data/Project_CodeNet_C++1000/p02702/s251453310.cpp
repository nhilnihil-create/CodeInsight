#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int n= s.length();
    reverse(s.begin(), s.end());

    vector<int> mod(n+1);
    int pow10 = 1;
    for(int i=0; i<n; i++){
        mod[i+1] = mod[i] + (s[i] - '0') * pow10;
        mod[i+1] %= 2019;

        pow10 *= 10;
        pow10 %= 2019;
    }

    map<int, int> pool;
    for(int i=0; i<=n; i++){
        if(pool.find(mod[i]) == pool.end()) pool[mod[i]] = 1;
        else pool[mod[i]] += 1;
    }

    long long int ans = 0;
    for(auto p : pool){
        ans += p.second * (p.second - 1) / 2;
    }
    cout << ans << endl;
    return 0;
}