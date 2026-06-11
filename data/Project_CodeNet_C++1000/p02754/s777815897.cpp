#include<bits/stdc++.h>
using ll = long long;
using namespace std;

int main(){
    ll n, a, b;
    cin >> n >> a >> b;

    ll res=0;
    ll rem=0;
    res = n/(a+b) * a;
    rem = n%(a+b);
    res += min(rem, a);

    cout << res << endl;
    return 0;
}