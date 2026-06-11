/**
*    author:  souzai32
*    created: 14.08.2020 01:03:59
**/

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {

    int n;
    cin >> n;
    vector<tuple<int,int>> rob(n);
    int x,l;
    rep(i,n){
        cin >> x >> l;
        rob.at(i)=make_tuple(x+l,x-l);
    }
    sort(rob.begin(),rob.end());

    int count=1,right=get<0>(rob.at(0));
    for(int i=1; i<n; i++){
        if(get<1>(rob.at(i))>=right){
            count++;
            right=get<0>(rob.at(i));
        }
    }
    
    cout << count << endl;

    return 0;
}