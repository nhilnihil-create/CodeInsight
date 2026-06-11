#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> mp;
ll inf =  1e9;


int main(){
 ll a,v,b,w;
 cin>>a>>v>>b>>w;
 ll d = abs(a-b);
 ll t;
 cin>>t;
 if( d <= t*(v-w) )cout<<"YES"<<endl;
 else cout<<"NO"<<endl;
    return 0;
}
