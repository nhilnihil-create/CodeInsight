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
  int a,b,c,d;cin>>a>>b>>c>>d;
  int tmp1=a,tmp2=c;
  while(true){
    tmp2-=b;
    if(tmp2<=0){
      cout<<"Yes"<<endl;
      break;
    }
    tmp1-=d;
    if(tmp1<=0){
      cout<<"No"<<endl;
      break;
    }
  }
return 0;
}