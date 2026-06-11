#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(x) begin(x), end(x)
using namespace std;
typedef long long ll;
typedef pair <int,int> P;

int main(){
  ll x,k,d;
  cin>>x>>k>>d;
  x=abs(x);
  
  ll need=x/d;
  if(need>=k){
    cout<<x-d*k<<endl;
    return 0;
  }
  ll nokori=k-x/d;
  if(nokori%2==0){
    cout<<x%d<<endl;
  }
  else{
    cout<<d-x%d<<endl;
  }
  return 0;
}
