#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define vll vector<pair<ll, ll>
using namespace std;


int main(){
    ios_base::sync_with_stdio(true);
    cin.tie(NULL);
    ll n, ans = 0;
    cin >> n;
    string s;
    cin >> s;
    
    for(ll i=0; i<n-2; i++){
        if (s.substr(i, 3) == "ABC"){
            ans += 1;
        }
    }
    cout << ans << endl;
    return 0;
}