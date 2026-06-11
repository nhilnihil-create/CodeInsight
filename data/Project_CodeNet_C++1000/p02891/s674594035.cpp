#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    string s;ll k;cin >> s >> k;
    ll q=0;

    bool w=true;
    for(int i = 1; i < s.size(); i++) {
        if(s[i]!=s[0]) w=false;
    }
    if(w){
        ll z=s.size();
        cout << z*k/2 << endl;
        return 0;
    }
    ll a=1,b=1;
    if(s[0]==s[s.size()-1]){
        
        for(int i = 1; i < s.size(); i++) {
            if(s[i]!=s[0]) break;
            a++;
        }
        for(int i = s.size()-2; i >0; i--) {
            if(s[i]!=s[0]) break;
            b++;
        }
    }
    ll c=0,d=1;
    char x=s[0];
    for(int i = 1; i < s.size(); i++) {
        if(s[i]==s[i-1]) d++;
        else{
            d/=2;
            c+=d;
            x=s[i];
            d=1;
        }
    }
    d/=2;
    c+=d;

    if(s[0]==s[s.size()-1]){
        cout << c*k+(k-1)*((a+b)/2-a/2-b/2) << endl;
    }
    else{
        cout << c*k << endl;
    }


    return 0;
}
