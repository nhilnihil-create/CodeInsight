// I SELL YOU...! 
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
signed main(){
  ll t0,t1,a0,a1,b0,b1;
  ll cnt=0;
  ll p1,p0,diff;
  cin >> t0 >> t1 >> a0 >> a1 >> b0 >> b1;
  p0 = t0*(a0-b0);
  p1 = p0 + t1*(a1-b1);
  if(p1==0){
    cout << "infinity"<<endl;
    return 0;
  }
  if((p0>0&&p1>0)||(p0<0&&p1<0)){
    cout << 0 << endl;
    return 0;
  }
  if(p1<0){
    p0 *= -1;
    p1 *= -1;
  } 
  cnt++;
  cnt += (-p0 / p1)*2;
  if((-p0)%p1 == 0) cnt--;
  cout << cnt << endl;
}
