#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
	
ll mod = 1e9 + 7;
 
int main(){
	ll n, a, b, c, d; cin >> n >> a >> b >> c >> d;
    string s; cin >> s;
    s.push_back('.');
    a--;b--;c--;d--;
    for(ll i = a; i < c; ++i){
        if(s[i] == '#' && s[i + 1] == '#'){
            cout << "No";
            return 0;
        }
    }
    for(ll i = b; i < d; ++i){
        if(s[i] == '#' && s[i + 1] == '#'){
            cout << "No";
            return 0;
        }
    }
    if(c == d){
        cout << "No";
        return 0;
    }
    if(d > c){
        cout << "Yes";
    }else{
        for(ll i = b; i <= d; ++i){
            if(s[i] == '.' && s[i - 1] == '.' && s[i + 1] == '.'){
                cout << "Yes";
                return 0;
            }
        }
        cout <<"No";
    }
    return 0;
}
