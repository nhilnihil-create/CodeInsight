#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//WA

int main(){
    ll n;
    cin >> n;
    vector<int> a(n);
    for(ll i=0; i<n; i++){
        cin >> a.at(i);
    }
    vector<ll> ans(n);
    for(ll i=n-1; i>=0; i--){
        //ans.at(i)を後ろから決める
        ans.at(i) = a.at(i);
        if(ans.at(i) == 0) continue;
        for(ll j=1; j*j<=(i+1); j++){
            if((i+1)%j == 0){
                a.at(j-1) = 1-a.at(j-1);
                ll m = (i+1)/j;
                if(m*m>(i+1) & m!=(i+1)) a.at(m-1) = 1-a.at(m-1);
            }
        }
    }
    ll sum_ball=0;
    for(ll i=0; i<n; i++){
        sum_ball += ans.at(i);
    }
    cout << sum_ball << endl;
    for(ll i=0; i<n; i++){
        if(ans.at(i) == 1){
            cout << i+1 << ' ';
        }
    }
}
