#include <bits/stdc++.h>
#include <climits>
#include <sstream>
using namespace std;

int main() {
    string S;
    cin >> S;
    map<long long,long long> mp;
    mp[0] = 1;
    long long now = 0, ten = 1;    
    for(int i = S.size()-1; i >= 0;i--){
        now = (now + ( S[i] - '0') * ten) % 2019;
        ten *= 10;
        ten %= 2019;
        mp[now]++;
    }
    long long ans = 0;
    for(auto m:mp){
        ans += m.second*(m.second-1)/2;
    }
    cout << ans << endl;
    
    
}
