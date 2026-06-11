#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(int i=0; i<(n); ++i)

int main(){
    ll n, k;
    ll mini=0;
    ll minas=0;
    cin >> n >> k;
    mini = n%k;
    minas = abs(mini-k);
    if(mini < minas)
        cout << mini << endl;
    else
        cout << minas << endl;
    return 0;
}