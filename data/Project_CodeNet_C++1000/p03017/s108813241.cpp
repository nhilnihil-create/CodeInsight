#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1LL << 60;
const ll MOD = 1e9 + 7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n,a,b,c,d;
    string s;
    cin >> n >> a >> b >> c >> d >> s;
    a--;
    b--;
    c--;
    d--;

    bool ans = true;

    for (ll i = a; i <= max({c-1,d-1}); i++){
        if (s[i] == '#' && s[i+1] == '#'){
            ans = false;
        }
    }

    if (c < d){
        if (ans){
            cout << "Yes" << endl;
        }
        else{
            cout << "No" << endl;
        }
        return 0;
    }

    if (!ans){
        cout << "No" << endl;
        return 0;
    }

    bool ans2 = false;

    for (ll i = b-1; i <= d-1; i++){
        if (s[i] == '.' && s[i+1] == '.' && s[i+2] == '.'){
            ans2 = true;
        }
    }
    
    if (ans2){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }

}