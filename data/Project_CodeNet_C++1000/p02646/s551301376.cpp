#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
int main(){
    ll a, b; ll v,w;
    cin>>a>>v;
    cin>>b>>w;
    ll t; cin>>t;
    ll t1 = abs(a-b);
    ll t2 = (v-w)*t;
    if(t1<=t2){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
    return 0;
}