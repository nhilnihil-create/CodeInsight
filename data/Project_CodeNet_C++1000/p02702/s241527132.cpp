/*
    Code written by Talant I.D.
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

#define precision(n) fixed << setprecision(n)
#define pb push_back
#define ub upper_bound
#define lb lower_bound
#define mp make_pair
#define eps (double)1e-9
#define PI 2*acos(0.0)
#define sz(v) int(v.size())
#define endl "\n"
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define do_not_disturb ios::sync_with_stdio(0);cin.tie(0);

inline bool isvowel(char ch){
    ch = tolower(ch);
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

const int INF = 0x3f3f3f3f;

inline bool isprime(int n){
    if(n < 2 || (n%2 == 0 && n != 2)) return false;
    for(int i = 3; i*i <= n; i += 2)
        if(n%i == 0) return false;
    return true;
}

const int mod = 2019;

int main(){
    do_not_disturb

    string s;
    vector <int> rem(mod);
    ll ans = 0;
    int num = 0, pw = 1;

    cin >> s;
    rem[0]++;

    for(int i = sz(s)-1; i >= 0; i--){
        num = (int(s[i]-'0')*pw+num)%mod;
        ans += rem[num]*1ll;
        rem[num]++;
        pw = (pw*10)%mod;
    }

    cout << ans;

    return 0;
}
