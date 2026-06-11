#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    string s;
    cin >> s;
    
    bool w=true;
    string forth,back;
    int q;
    cin >> q;
    for(int i = 0; i < q; i++) {
        int t;
        cin >> t;
        if(t==1) w = !w;
        else{
            int f;
            cin >> f;
            char c;
            cin >> c;
            if(w==true && f==1) forth += c;
            else if(w==false && f==2) forth += c;
            else back += c ;
        }
    }
    string ans;

    if(w==true){
        reverse(forth.begin(),forth.end());
        ans += forth;
        ans += s;
        ans += back;

        cout << ans << endl;
    }
    else{
        reverse(s.begin(),s.end());
        reverse(back.begin(),back.end());
        ans += back;
        ans += s;
        ans += forth;

        cout << ans << endl;
    }
    return 0;
}