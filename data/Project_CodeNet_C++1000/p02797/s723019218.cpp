/**
*    author:  souzai32
*    created: 02.08.2020 13:17:06
**/

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {

    long int n,k,s;
    cin >> n >> k >> s;

    vector<int> num(n,s);

    for(int i=k; i<n; i++){
        num.at(i)++;
        if(s==1000000000) num.at(i)=1;
    }

    rep(i,n) cout << num.at(i) << ' ';
    cout << endl;

    return 0;
}