#include <bits/stdc++.h>
#define ll long long
#define ar array
#define nl '\n'
#define AC ios_base::sync_with_stdio(0); cin.tie(NULL);
using namespace std;
const int M = 1e9+7;
const int N = 2*1e5;



int main(){
    AC
    ll x;
    cin>>x;
    for(ll i=-1000; i<=1000; i++){
        for(ll j=-1000; j<=1000; j++){
            if(pow(i,5)-pow(j,5)==x){
                cout<<i<<" "<<j<<endl;
                return 0;
            }
        }
    }

}