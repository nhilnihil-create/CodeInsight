#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    string S; cin >> S;
    rep(i, S.size()){
        if(i%2 == 1){
            if(S[i] == 'R'){
                cout << "No" << endl;
                return 0;
            }
        } else {
            if(S[i] == 'L'){
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;

    return 0;
}