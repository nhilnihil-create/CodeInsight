#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main (void){
    string S,T;
    cin >> S;
    cin >> T;
    T.erase(T.length()-1);
    if(S == T) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}