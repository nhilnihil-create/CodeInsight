//Moh_K_Imar .......
//26/08/2020  ... 3,25.
//Ya Rab....
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
int main(){
    ll a;
    cin>>a;
    ld counter=0;
    for(ll i=1;i<=a;i++){
        if(i%2==1)counter++;
    }
    cout<<setprecision(10)<<fixed<<counter/a<<endl;

    return 0;
}

