//Moh_K_Imar .......
//22/08/2020  ... 11,47
//Ya Rab....
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
int main(){
    string a;
    cin>>a;
    ll counter=0;
    for(ll i=0;i<a.size();i++){
        if(a[i]=='7')counter++;
    }
    if(counter!=0)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

    return 0;
}

