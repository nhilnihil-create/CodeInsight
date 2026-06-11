#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n,a,b,c,d;
    cin >> n >> a >> b >> c >> d;
    string s;
    cin >> s;

    bool x=true,y=false;
    for(int i = a; i < d-2; i++) {
        if(s[i]=='#' && s[i+1]=='#'){
            x=false;
        }
    }
    for(int i = a; i < c-2; i++) {
        if(s[i]=='#' && s[i+1]=='#'){
            x=false;
        }
    }
    
    for(int i = b-2; i < d-1; i++) {
        if(s[i]=='.' && s[i+1]=='.' && s[i+2]=='.'){
            y=true;
        }
    } 


    if(c<d){
        if(x) cout << "Yes" << endl;
        else cout << "No" << endl;
    }  
    else{
        if(x && y) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

    return 0;
}