//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for(int i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;
const int mod =1e+9+7;

int main(){
    ll x; cin>>x;
    for (ll i=-130;i<=130;i++){
        for(ll j=-130;j<=130;j++){
            if(i*i*i*i*i-j*j*j*j*j==x){
                cout<<i<<" "<<j<<endl;
                return 0;
            }
        }
    }
}






































