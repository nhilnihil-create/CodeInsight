#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main(){
    string s; cin >> s;
    ll n = s.length();
    ll left[n + 24] = {0};
    ll right[n + 24] = {0};
    for(ll i = 0; i < n; ++i){
        if(s[i] == '<'){
            left[i + 1] = left[i] + 1; 
        }else left[i + 1] = 0;
    }
    for(ll i = n; i >= 1; --i){
        if(s[i] == '>'){
            right[i] = right[i + 1] + 1; 
        }else right[i] = 0;
    }
    ll sum = 0;
    if(s[0] == '<'){
        left[0] = 0;
    }
    else if(s[0] == '>'){
        left[0] = max(left[1], right[1]) + 1;
    }
    if(s[n - 1] == '<'){
        right[n] = max(left[n - 1], right[n - 1]) + 1;
    }
    else if(s[n - 1] == '>'){
        right[n] = 0; 
    }
    for(ll i = 0; i < n + 3; ++i){
        sum += max(left[i], right[i]);
    }
    cout << sum;
    return 0;
}
