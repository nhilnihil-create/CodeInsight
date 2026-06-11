#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll S;
    cin >> S;
    ll lm = 1e9;
    ll x = 0;
    if(S % lm != 0) x = (lm - S%lm);
    ll y = (S + x) / lm;
    cout << "0 0 " << lm << " 1 " << x << " " << y << endl; 
    return 0;
}