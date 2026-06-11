#include "bits/stdc++.h"
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll =long long;
using P =pair<int,int>;

int main(){
    int n;
    cin >> n;
    vector <int> w(n);
    vector <int> wa(n);
    int wa2=0;
    rep(i,n){
        cin >> w[i];
        wa2+=w[i];
        wa[i]=wa2;
    }

    int j;
    rep(i,n){
        if(wa[i]>(wa2/2)){
            j=i;
            break;
        }
    }

    int ans;
    ans=min((wa2-2*wa[j-1]),wa[j]-(wa2-wa[j]));
    cout << ans << endl;
    

    return 0;
}