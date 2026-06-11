#include <bits/stdc++.h>
using namespace std;


#define ll long long
#define MOD 1000000007
#define PI 3.1415


int main(){
    ll x;
    cin>>x;

    ll a,b;
    ll ansa,ansb;
    for(ll i=-118;i<120;i++){
        for(ll j=-119;j<119;j++){
            a = i*i*i*i*i;
            b = j*j*j*j*j;
            if(a-b==x){
                ansa = i;
                ansb = j;
                break;
            }
        }
    }
    cout<<ansa<<" "<<ansb<<endl;

}
