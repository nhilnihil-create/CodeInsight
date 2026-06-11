#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main(){
    string s;
    cin >> s;
    string a, b;
    rep(i,s.size()){
        if((i + 1) % 2 == 0){
            b.push_back(s[i]);
        }else{
            a.push_back(s[i]);
        }
    }
    rep(i, a.size()){
        if(a[i] != 'R' && a[i] != 'U' && a[i] != 'D'){
            cout << "No" << endl;
            return 0;
        }
    }
    rep(i, b.size()){
        if(b[i] != 'L' && b[i] != 'U' && b[i] != 'D'){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}