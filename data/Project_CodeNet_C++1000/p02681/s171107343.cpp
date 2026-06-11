//##Moh_K_Imar .......
//27/08/2020  ...  8.26
//Ya Rab....
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
int main(){
    string a,b;
    cin>>a>>b;
    ll counter=0;
    for(ll i=0;i<b.size();i++){
        if(a[i]==b[i])counter++;
    }
    if(counter==a.size())cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

    return 0;
}

