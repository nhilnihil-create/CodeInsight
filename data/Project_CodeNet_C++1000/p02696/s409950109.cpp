/*
      author : Nishikawa
      created: 10.08.2020 20:05:37
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int a;
    ll b,n;
    cin >> a >> b >> n;
    ll x;
    x = min(b-1, n);
    cout << floor(a*x/b) - a*floor(x/b) << endl;
    return 0;
}