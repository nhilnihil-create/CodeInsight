/**
*    author:  souzai32
*    created: 14.08.2020 16:26:53
**/

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {

    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a.at(i);
    vector<int> x(n,0);

    for(int i=0; i<n; i++){
        if(i%2) x.at(0)-=a.at(i);
        else x.at(0)+=a.at(i);
    }
    for(int i=1; i<n; i++){
        x.at(i)=2*a.at(i-1)-x.at(i-1);
    }
    for(int i=0; i<n; i++){
        if(i!=n-1) cout << x.at(i) << ' ';
        else cout << x.at(i) << endl;
    }

    return 0;
}