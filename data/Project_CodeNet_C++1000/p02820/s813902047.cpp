/**
*    author:  souzai32
*    created: 02.08.2020 19:41:11
**/

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {

    int n,k;
    cin >> n >> k;
    int r,s,p;
    cin >> r >> s >> p;
    long long point=0;
    string t;
    cin >> t;

    rep(i,n){
        if(t.at(i)=='r') point+=p;
        if(t.at(i)=='s') point+=r;
        if(t.at(i)=='p') point+=s;
    }

    for(int i=k; i<n; i++){
        if(t.at(i)==t.at(i-k)){
            if(t.at(i)=='r') point-=p;
            if(t.at(i)=='s') point-=r;
            if(t.at(i)=='p') point-=s;
            t.at(i)='a';
        }
    }

    cout << point << endl;

    return 0;
}