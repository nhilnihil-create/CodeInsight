#include<bits/stdc++.h>
using namespace std;
int main(){
        long long int n; cin >> n;
        map<string, long long int> mp;
        for (long long int x = 0; x < n; ++x){
            string s; cin >> s;
            sort(s.begin(), s.end());
            mp[s]++;
        }
        long long int ans = 0;
        for (auto x : mp){
            long long int q = x.second;
            if (q == 1) continue;
            q = q * (q - 1) / 2;
            ans += q;
        }
        cout << ans << endl;
    return 0;
}
