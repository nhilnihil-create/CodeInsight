//Moh_K_Imar .......
//26/08/2020  ... 3,41.
//Ya Rab....
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
int main(){
    string a,b;
    cin>>a>>b;
    ll counter=0;
    for(ll i=0;i<a.size();i++){
        if(a[i]==b[i])counter++;
    }
    cout<<counter<<endl;

    return 0;
}

