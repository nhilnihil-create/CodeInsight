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
   int n;
   cin>>n;
   vin a(n);
   Graph yaku(1e6+11);
   rep(i,1e6+10){
       int j=i+1;
       for(int k=2;k*j<=1e6+10;k++){
           yaku[k*j].pb(j);
       }
   }
   
   set<int> ay;
   set<int> ww;
   rep(i,n){
       cin>>a[i];
       if(ay.count(a[i])){
           ww.it(a[i]);
           continue;
       }
       ay.it(a[i]);
   }
   int cnt=0;
   rep(i,n){
       if(ww.count(a[i])){
           cnt++;
           continue;
       }
       for(auto x:yaku[a[i]]){
           if(ay.count(x)){
               cnt++;
               break;
           }
       }
   }
   cout<<n-cnt<<endl;
   
  
  
   
}
