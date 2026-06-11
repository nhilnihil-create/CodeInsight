/*
      author : nishi5451
      created: 11.08.2020 22:12:15
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    ll a,b;
    cin >> a >> b;
    ll k;
    if(a%2 == b%2) cout << (max(a,b) + min(a,b))/2 << endl;
    else cout << "IMPOSSIBLE" << endl;
    return 0;
}