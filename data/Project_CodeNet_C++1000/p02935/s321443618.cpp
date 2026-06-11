#include<bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
using namespace std;

int main(){
    int n;
    cin >> n;
    double input[n];
    rep(i, n) cin >> input[i];
    sort(input, input+n);
    double res = input[0];
    for(int i=0; i<n; i++) res = (res + input[i])/2;
    cout << res << endl;
    return 0;
}