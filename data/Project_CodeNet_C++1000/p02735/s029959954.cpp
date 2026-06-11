/**
*    author:  souzai32
*    created: 13.08.2020 12:33:54
**/

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {

    int h,w;
    cin >> h >> w;
    vector<vector<char>> s(h,vector<char>(w));
    rep(i,h){
        rep(j,w) cin >> s.at(i).at(j);
    }
    vector<vector<int>> n(h,vector<int>(w));
    int num1,num2;

    for(int i=1; i<h+w-1; i++){
        for(int j=0; j<=i; j++){
            int k=i-j;
            if(j>=h || k>=w) continue;
            if(j!=0){
                num1=n.at(j-1).at(k);
                if(s.at(j-1).at(k)!=s.at(j).at(k)) num1++;
            }
            if(k!=0){
                num2=n.at(j).at(k-1);
                if(s.at(j).at(k-1)!=s.at(j).at(k)) num2++;
            }
            n.at(j).at(k)=min(num1,num2);
            num1=10000;
            num2=10000;
        }
    }
    
    int ans=n.at(h-1).at(w-1);
    ans/=2;
    if(s.at(0).at(0)=='#'||s.at(h-1).at(w-1)=='#') ans++;
    cout << ans << endl;
/*
    cout << endl;
    rep(i,h){
        rep(j,w) cout << n.at(i).at(j);
        cout << endl;
    }*/

    return 0;
}