#include<bits/stdc++.h>
#include<stdio.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define pb                  push_back
#define arr                 vector<ll>
#define mem(x,val)          memset(x,val,sizeof(x))
#define vp                 vector<pair<ll,ll>>
#define matrix              vector<vector<ll> >
#define digit(x)            floor(log10(x))+1
#define debug(x)            cerr << #x << " is " << x << endl;
#define all(a)              a.begin(),a.end()
#define fixed               setprecision(15)
// ll dx[]={-1,1,0,0},dy[]={0,0,-1,1}; 4 Sides
//ll dx[]={-1,1,-1,1,0,0,-1,1} , dy[]={-1,1,0,0,-1,1,1,-1};    8 Sides
using namespace std;
arr read(ll n){
    arr a;
    for (ll i=0;i<n;i++){
        ll x;
        cin>>x;
        a.pb(x);
    }
    return a;
}
  int main(){
       ll x, k, d;
       cin >> x >> k >> d;
       x = abs(x);
       
       ll step = x/d;
       ll c = min(step, k);

       k = k - c;
       x = x - c*d;

       if (k&1){
           cout<<abs(x-d)<<endl;
       }else{
           cout<<x<<endl;
       }

        return 0;
}
