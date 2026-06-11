#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, a, b, c, d;
    string s;
    cin >> n >> a >> b >> c >> d >> s;
    a -= 1;
    b -= 1;
    c -= 1;
    d -= 1;

    for(int i=b+1; i+1<=d-1; i++){
        if(s[i] == '#' && s[i+1] == '#'){
            cout << "No" << endl;
            return 0;
        }
    }
    for(int i=a+1; i+1<=c-1; i++){
        if(s[i] == '#' && s[i+1] == '#'){
            cout << "No" << endl;
            return 0;
        }
    }

    bool flag = false;
    for(int i=b; i<=d; i++){
        if(s[i-1] == '.' && s[i] == '.' && s[i+1] == '.') flag = true;
    }
    if(c > d && flag == false) cout << "No" << endl;
    else cout << "Yes" << endl;
    return 0;
}