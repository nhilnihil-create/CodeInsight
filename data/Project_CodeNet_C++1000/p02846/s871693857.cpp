#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  ll t1,t2,a1,a2,b1,b2;
  cin>>t1>>t2>>a1>>a2>>b1>>b2;
  if(a1*t1+a2*t2==b1*t1+b2*t2){
    cout << "infinity" << endl;
    return 0;
  }
  ll ok = 0,ng = 1e16;
  ll a = a1*t1+a2*t2;
  ll b = b1*t1+b2*t2;
  ll last = 0;
  while(ng-ok>1){
    ll mid = (ng+ok)/2;
    ll ax0 = a*(mid-1);
    ll bx0 = b*(mid-1);
    ll ax1 = a*(mid-1)+a1*t1;
    ll ax2 = a*mid;
    ll bx1 = b*(mid-1)+b1*t1;
    ll bx2 = b*mid;
    bool cr1 = (ax0<bx0&&ax1>=bx1)|| (ax0>bx0&&ax1<=bx1);
    bool cr2 = (ax1<bx1&&ax2>=bx2)|| (ax1>bx1&&ax2<=bx2);
    if(cr1 || cr2){
      ok = mid;
      last = cr1+ cr2;
    }else{
      ng = mid;
    }
  }
  ll ans=0;
  if(ok==1){
    ans = last;
  }else if(ok){
    ans = ok*2-1;
    if(last==1)ans--;
  }
  cout << ans << endl;
}

