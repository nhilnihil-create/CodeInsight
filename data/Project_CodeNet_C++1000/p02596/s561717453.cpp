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
      ll n;
      cin >> n;
      if (n%2==0){
          cout<<-1<<endl;
      }else{
          if (n%5==0){
              cout<<-1<<endl;
          }else{
              ll x = 7%n;
              bool ok=0;
              ll ans=-1;
              for (ll i=1;i<=(ll)1e7;i++){
                    if (x == 0){
                        ans = i;
                        break;
                    }
                    x = (x*10 + 7) % n;
              }
              cout<<ans<<endl;
          }
      }
        return 0;
}
