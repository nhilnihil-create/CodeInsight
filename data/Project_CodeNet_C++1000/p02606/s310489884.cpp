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
  int l,r,d;
  cin>>l>>r>>d;
  int cnt=0;

  for(int i=l;i<=r;++i){
    if(i%d==0) ++cnt;
  }
  cout<<cnt<<endl;
return 0;
}