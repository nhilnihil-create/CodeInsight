#include <iostream>
using namespace std;
#define LIMIT1 200010
#define LIMIT2 500010
typedef long long ll;
typedef long double ld;
typedef const void cv;
//BIT start
const int MAX_N=LIMIT2;
ll bit[MAX_N+1]={0},n;
//1-indexed BIT
ll sum(int i){
  ll s=0;
  while(i>0){
    s += bit[i];
    i -= i&(-i);
  }
  return s;
}
void add(int i,ll x){
  while(i<=n){
    bit[i] += x;
    i += i&(-i);
  }
}
ll rangesum(int l,int r){
  return sum(r)-sum(l-1);
}
//BIT end
int main(){
  ll i,q,x;
  cin >> n >> q;
  for(i=1;i<=n;i++){
    cin >> x;
    add(i,x);
  }
  int t,a,b;
  for(i=1;i<=q;i++){
    cin >> t >> a >> b;
    if(t==0) add(a+1,(ll)b);
    else cout << rangesum(a+1,b) << endl;
  }
  return 0;
}