#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)

int main(){
    string a, b;
    cin >> a >> b;
    string S = "", T = "";
    int _a = (int)stoi(a);
    int _b = (int)stoi(b);
    //aをb回
    rep(i, _b) S += a;
    //bをa回
    rep(i, _a) T += b;
    if(S < T) cout << S << endl;
    else cout << T << endl;
    return 0;
}