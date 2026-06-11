#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll a, b, c;
    cin >> a >> b >> c;
    ll d = c - (a + b);
    if(d > 0) {
        if(4 * a * b < d * d) cout << "Yes" << endl;
        else cout << "No" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}