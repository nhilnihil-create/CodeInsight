#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl '\n'
#define pb push_back
#define ll long long
#define ull unsigned long long
#define vi vector<int>
using namespace std;
constexpr int MOD=1e9+7;

const int mod = 2019 ; 



int main() {
    string s  ; 
    cin >> s ; 
    ll ans = 0 ; 
    int suff = 0;
    int power = 1  ;
    int n = s.size() ; 
    map<int,int> cnt ; 
    cnt[suff]++; 
    for(int i = n -1 ; i >= 0 ; --i) {
        int digit = s[i] - '0' ; 
        suff = (suff + digit * power ) % mod ; 
        power = (power * 10 ) % mod ; 
        ans += cnt[suff] ; 
        cnt[suff]++;
    } 

    cout << ans << endl ;

    return 0 ; 
}

