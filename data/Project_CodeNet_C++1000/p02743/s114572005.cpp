#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep1(i,n) for (int i = 1; i <= (n); ++i)

using namespace std;
using ll = long long;
using P = pair<int,int>;
using ull= unsigned long long;
const ll K_MAX=1e5+5;


// a+b+2sqrt(a*b)<c
// 2*sqrt(a*b)<c-a-b
// 4*a*b<(c-a-b)**2
int main(){
  ll a,b,c;
  cin >>a>>b>>c;
  string ans;
  if (c-a-b<0){
    ans="No";
  }else{
    if((c-a-b)*(c-a-b)>4*a*b){
    ans="Yes";
    }else{
    ans="No";
    }

  }

  cout<<ans<<endl;

}
