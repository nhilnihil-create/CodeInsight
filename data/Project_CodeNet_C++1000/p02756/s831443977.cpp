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
   string s;
   int q;
   cin>>s>>q;
   deque<char> r;
   rep(i,s.size()) r.pb(s[i]);
   bool str=true;
   rep(i,q){
       int ti;
       cin>>ti;
       if(ti==1){
           str=!str;
           continue;
       }
       int fi;
       char ci;
       cin>>fi>>ci;
       if(str){
           if(fi==1) r.push_front(ci);
           else r.pb(ci);
       }
       else{
           if(fi==2) r.push_front(ci);
           else r.pb(ci);
       }
   }
   if(str){
       rep(i,r.size()){
           cout<<r.at(i);
           
       }
       cout<<endl;
       return 0;
   }
   rep(i,r.size()){
           cout<<r.at(r.size()-i-1);
   }
   cout<<endl;
}
