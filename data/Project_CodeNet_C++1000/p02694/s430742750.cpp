#include<bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using P = pair<int,int>;
using ll = long long;
using namespace std;
int main(void){
    // Your code here!
    ll x; cin >> x;
    ll yokin = 100;
    
    rep(i, x){
        yokin += yokin / 100;
        if(yokin >= x){cout << i+1 << endl; return 0;}
    }
}
