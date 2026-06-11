#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main() {
    ll n,a,b,c,d;
    cin >> n >> a >> b >> c >> d;
    string s;
    cin >> s;
    bool ok1=true;
    for(ll i=a;i<c-1;i++){
        if(s[i]=='#'&&s[i+1]=='#') ok1=false;
    }
    bool ok2=true;
    for(ll i=b;i<d-1;i++){
        if(s[i]=='#'&&s[i+1]=='#') ok2=false;
    }
    bool ok3=false;
    if(c<d) ok3=true;
    for(ll i=b-1;i<=d-1;i++){
        if(s[i-1]=='.'&&s[i]=='.'&&s[i+1]=='.') ok3=true;
    }
    if(ok1&&ok2&&ok3) cout << "Yes" << endl;
    else cout << "No" << endl;
}