#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using namespace std;
using P = pair<int,int>;

static bool S(string s){
    bool a = true;
    for(int i = 0; i < s.length(); i++){
        if(i%2 == 0){
            if(s[i] == 'L'){
                a = false;
                break;
            }
        }
        else{
            if(s[i] == 'R'){
                a = false;
                break;
            }
        }
    }

    return a;
}

int main(){
    string s;
    cin >> s;
    cout << (S(s) ? "Yes" : "No") << endl;
    return 0;
}