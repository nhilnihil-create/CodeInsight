#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using ll = long long;

int main(){
    vector<int> a(5);
    rep(i,5) cin >> a[i];
    rep(i,5){
        if(a[i]==0) cout << i+1 << endl;
    }
}