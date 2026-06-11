/**
*    author:  souzai32
*    created: 01.08.2020 17:08:08
**/

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {

    long long int a,b,c;
    cin >> a >> b >> c;

    string ans="Yes";
    if(c-a-b<0) ans="No";
    else{
        if(a*a+b*b+c*c-2*a*b-2*b*c-2*c*a<=0) ans="No"; 
    }
    cout << ans << endl;

    return 0;
}