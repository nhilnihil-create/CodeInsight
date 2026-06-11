/**
*    author:  souzai32
*    created: 05.08.2020 01:04:23
**/

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {

    int n;
    cin >> n;
    vector<int> l(n);
    rep(i,n) cin >> l.at(i);
    sort(l.begin(),l.end(),greater<>());
    int count=0;

    for(int i=0; i<n-2; i++){
        for(int j=i+1; j<n-1; j++){
            for(int k=j+1; k<n; k++){
                if(l.at(i)<l.at(j)+l.at(k)){
                    count++;
                    //cout << l.at(i) << ' ' << l.at(j) << ' ' << l.at(k) << endl;
                }
                else break;
            }
            if(l.at(i)>l.at(j)*2) break;
        }
    }

    cout << count << endl;

    return 0;
}