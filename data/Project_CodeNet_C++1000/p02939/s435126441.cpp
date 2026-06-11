#include <bits/stdc++.h>
#define pb push_back
#define rep(i,n) for(ll i = 0;i < (n); ++i)
typedef long long ll;
typedef long double la;
using namespace std;

int main(){
    string s;
    cin >> s;
    int ans = 0;
    string a,b;
    rep(i,s.size()){
        a += s[i];
        if(a != b){
            b = a;
            ans++;
            a = "";
        }
    }
    cout << ans << endl;
} 