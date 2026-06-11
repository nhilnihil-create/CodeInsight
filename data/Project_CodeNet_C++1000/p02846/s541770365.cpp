#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
const ll MOD = 1000000007;
const ll INF = 1000000000000000000;
#define all(v) v.begin(), v.end()


int main(){
  ll t1,t2,a1,a2,b1,b2;
  cin >> t1 >> t2 >> a1 >> a2 >> b1 >> b2;
  if(t1*a1+t2*a2==t1*b1+t2*b2){
    cout << "infinity" << endl;
  }else if((a1>b1&&t1*a1+t2*a2>t1*b1+t2*b2)||(a1<b1&&t1*a1+t2*a2<t1*b1+t2*b2)){
    cout << 0 << endl;
  }else if(a1>b1){
    if(((a1-b1)*t1)%(t1*b1+t2*b2-t1*a1-t2*a2)==0){
      cout << (((a1-b1)*t1)/(t1*b1+t2*b2-t1*a1-t2*a2))*2 << endl;
    }else{
      cout << (((a1-b1)*t1)/(t1*b1+t2*b2-t1*a1-t2*a2))*2+1 << endl;
    }
  }else{
    if(((b1-a1)*t1)%(t1*a1+t2*a2-t1*b1-t2*b2)==0){
      cout << (((b1-a1)*t1)/(t1*a1+t2*a2-t1*b1-t2*b2))*2 << endl;
    }else{
      cout << (((b1-a1)*t1)/(t1*a1+t2*a2-t1*b1-t2*b2))*2+1 << endl;
    }
  }
    
}