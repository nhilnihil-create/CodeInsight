#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,n) for(int i=0; i<(int)(n); ++i)
#define REP(i,m,n) for(ll i=(ll)(m); i<(ll)(n); ++i)
#define F first
#define S second
const double PI=acos(-1);
//fixed<<setprecision(11)<<

int main(){
  string s;
  cin >> s;
  int n = s.size();
  int r = (n-1)/2;
  string s_inv = s;
  string s_pre = s.substr(0,r);
  string s_preinv = s_pre;

  reverse(s_inv.begin(),s_inv.end());
  if(s != s_inv){
    cout<<"No"<<endl;
    return 0;
  }

  reverse(s_preinv.begin(),s_preinv.end());
  if(s_pre != s_preinv){
    cout<<"No"<<endl;
    return 0;
  }

  cout<<"Yes"<<endl;
return 0;
}