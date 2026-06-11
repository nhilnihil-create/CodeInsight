#include <bits/stdc++.h>

using namespace std;
using Graph = vector<vector<int>>;
using Grid= vector<vector<char>>;
using vin= vector<int>;
using ll=long long;
using vll= vector<ll>;
using vbl=vector<bool>;
using vch=vector<char>;
using pnn=pair<int ,int>;

#define ft first
#define sd second
#define fn front
#define pb push_back
#define it insert
#define count ct
#define si(v) int((v).size())
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rell(i,n) for (ll i=0; i< (ll)(n); i++)
#define sot(x) sort(x.begin(), x.end())
#define rese(x) reverse(x.begin(), x.end())
#define vnn(x,y,s,name) vector<vector<int>> name(x, vector<int>(y,s))
#define mse(x) memset(x, 0, sizeof(x))
#define mii(x,y,z) min(x,min(y,z))
#define maa(x,y,z) max(x,max(y,z))

string yes="Yes",no="No";

int main() {
   ll n,k;
   cin>>n>>k;
   vll p(n),c(n);
   rep(i,n){
       cin>>p[i];
       p[i]--;
   }
   rep(i,n) cin>>c[i];
   ll ans=-(1e9);
   rep(i,n){
       ll x=i;
       ll sum=0;
       vll cpx,px;
       while(p[x]!=i){
           px.pb(x);
           sum+=c[p[x]];
           cpx.pb(sum);
           x=p[x];
       }
       px.pb(x);
       sum+=c[p[x]];
       cpx.pb(sum);
       ll len=px.size();
       if(k<len){
           rep(j,k){
               ans=max(ans,cpx[j]);
           }
           continue;
       }
       if(sum<0){
           rep(j,len){
               ans=max(ans,cpx[j]);
           }
           continue;
       }
       ll ansi=sum*((k/len)-1);
       ll lk=k%len;
       rep(j,len){
           ans=max(ans,ansi+cpx[j]);
       }
       ansi+=sum;
       rep(j,lk){
           ans=max(ans,ansi+cpx[j]);
       }
       
   }
   cout<<ans<<endl;
}
