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
   ll h;
   cin>>h;
   ll ans=0;
   queue<pair<ll,ll>> q;
   pair<ll,ll> h1;
   h1.ft=h;
   h1.sd=1;
   q.push(h1);
   while(!q.empty()){
       pair<ll,ll> r=q.front();
       q.pop();
       if(r.first==0) break;
       ans+=(ll)r.sd;
       r.sd*=2;;
       r.ft/=2;
       q.push(r);
       
      
   }
   cout<<ans<<endl;
}
