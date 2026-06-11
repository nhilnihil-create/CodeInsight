#include "bits/stdc++.h"
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll =long long;
using P =pair<int,int>;

int main(){
    int n;
    cin >> n;
    vector <vector <int>> s(10,vector <int> (10,0));


    int am,au,i2;
    ll ans;
    ans=0;

    rep(i,n){
        i2=i+1;
        au=i2%10;
        while(i2>=10){
            i2/=10;
        }
        am=i2;
        ++s[am][au];

    }

    rep(i,9){
        rep(j,9-i){
            if(j==0){
                ans+=s[i+1][i+1]*s[i+1][i+1];
            }
            else{
                ans+=s[i+1][j+i+1]*s[j+i+1][i+1]*2;
            }
        }
    }
        
    cout << ans << endl;
    

    return 0;
}