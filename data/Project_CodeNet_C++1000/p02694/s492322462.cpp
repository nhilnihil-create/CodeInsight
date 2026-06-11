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
  ll x;
  cin>>x;
  ll cnt=0;
  ll y=100;//yokin
  while(y<x){
  y+=y/100;
  cnt++;
  }
  cout<<cnt<<endl;
return 0;
}