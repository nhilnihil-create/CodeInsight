#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)

int main(){
    vector<int> N(4);

    rep(i,5){
        cin >> N[i];
    }
    rep(i,5){
        if(N[i]==0){cout << i+1 << endl; break; }
    }
}