// lcmとかはg++ -std=c++17 default.cppみたいなかんじで
//vector<vector<ll>> piyo(tate,vector<ll> (yoko));
 
#include <bits/stdc++.h>
#define mod 1000000007
#define INF 1000000000
#define ll long long
#define ln cout<<endl;
#define Yes cout<<"Yes"<<endl;
#define No cout<<"No"<<endl;
#define double long double
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
#define rep(i,n) REP(i,0,n)
using namespace std;
 
 int main(){
  string str;
   cin>>str;
	ll f=0;
  rep(i,str.length()){
    if(i%2){
      if(str[i]!='i') f=1;
    }
    else {
      if(str[i]!='h') f=1;
    }
    }
    if(str.length()%2) f=1;
  if(f) cout<<"No"<<endl;
  else cout<<"Yes"<<endl;
  return 0;
}
