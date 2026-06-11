/**
*    author:  souzai32
*    created: 13.08.2020 13:26:20
**/

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {

    int n,x,y;
    cin >> n >> x >> y;
    vector<int> d(n);
    int dist;

    for(int i=1; i<n; i++){
        for(int j=n; j>i; j--){
            dist=min(j-i,abs(x-i)+1+abs(y-j));
            d.at(dist)++;
        }
    }

    for(int i=1; i<n; i++) cout << d.at(i) << endl; 

    return 0;
}