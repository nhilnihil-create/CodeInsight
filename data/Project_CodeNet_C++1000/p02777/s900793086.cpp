//Moh_K_Imar .......
//24/08/2020  ... 5,35 .
//Ya Rab....
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
int main(){
    string s,t;
    cin>>s>>t;
    ll a,b;
    cin>>a>>b;
    string c;
    cin>>c;
    if(c==s){
        cout<<a-1<<" "<<b<<endl;
    }
    else {
        cout<<a<<" "<<b-1<<endl;
    }

    return 0;
}

