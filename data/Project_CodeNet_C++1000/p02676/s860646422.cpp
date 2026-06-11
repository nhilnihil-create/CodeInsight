#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i< (n); i++)
using namespace std;
using ll = long long;
typedef pair<int,int> P;

int main(void) {
    int K; cin >> K;
    string S; cin >> S;
    if(int(S.size()) <= K) cout << S << endl;
    else {
        string s = S.substr(0,K);
        s+="...";
        cout << s << endl;
    }
    return 0;
}