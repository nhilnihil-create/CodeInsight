/*
      author : nishi5451
      created: 11.08.2020 23:13:06
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int k,a,b;
    cin >> k >> a >> b;
    if(a<=b/k*k) cout << "OK" << endl;
    else cout << "NG" << endl;
    return 0;
}