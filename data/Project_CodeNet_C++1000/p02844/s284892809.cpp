#include <bits/stdc++.h>
typedef long long ll;
#define ALL(l)  (l).begin(),(l).end()
#define rep(i,n) for(ll (i)=0;(i)<(n);(i)++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;

//const ll mod =  1000000007;
//const ll maxn = 1000000000;

//---------------------------------------------------------------------------------------------------
using vi = vector<int>; // intの1次元の型に vi という別名をつける
using vll = vector<ll>; // intの1次元の型に vi という別名をつける
using vvll = vector<vll>; // intの2次元の型に vvi という別名をつける
using vs = vector<string>; // stringの1次元の型に vs という別名をつける
using pll = pair<ll, ll>; // これ以降 pii という型名はpair<ll, ll> と同じ意味で使える
//---------------------------------------------------------------------------------------------------

int main() {
    vi b(1000,0);
    
   int n,ans=0;
   cin>>n;
   string s;
   cin>>s;
   vi a(n);
   rep(i,n){
       a.at(i)=s.at(i)-'0';
   }
   rep2(i,1,n-1){
       
       int k=a.at(i);
       vi r(10,0),l(10,0);
       
       rep(j,i){
           l.at(a.at(j))=1;
       }
       rep2(j,i+1,n){
            r.at(a.at(j))=1;
       }
       rep(i,10){
           rep(j,10){
               if(l.at(i)==1&&r.at(j)==1){
                   b.at(100*i+10*k+j)=1;
               }
           }
       }
       
   }
   rep(i,1000){
       ans+=b.at(i);
   }
   cout<<ans<<endl;
    
}

