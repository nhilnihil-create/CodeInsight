#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
typedef long long ll;
typedef pair<int,int> P;
#define F first
#define S second
const double PI=acos(-1);
//fixed<<setprecision(11)<<

int main(){
  ll n,a;
  ll cnt=0;
  cin>>n;
  for(int i=1;i<=n;++i){
  cin>>a;
  if(i%2!=0&&a%2!=0) ++cnt;
  }

  cout<<cnt<<endl;
return 0;
}