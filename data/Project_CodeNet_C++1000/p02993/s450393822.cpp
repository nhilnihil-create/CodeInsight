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
  string s;cin>>s;
  
  if(s[0]==s[1]){
    cout<<"Bad"<<endl;
    return 0;
  }
  if(s[1]==s[2]){
    cout<<"Bad"<<endl;
    return 0;
  }
  if(s[2]==s[3]){
    cout<<"Bad"<<endl;
    return 0;
  }

  cout<<"Good"<<endl;
return 0;
}