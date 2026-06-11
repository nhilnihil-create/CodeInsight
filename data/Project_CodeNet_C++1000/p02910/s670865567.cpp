#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef float fl;
typedef long long ll;

int main(){
    string S; cin >> S;
    bool ok = true;
    rep(i,S.size()){
        if((i%2 == 0) && (S[i] == 'L')) ok = false;
        else if((i%2 == 1) && (S[i] == 'R')) ok = false;
    }
    cout << ((ok)? "Yes" : "No") << endl;
    return 0;
}