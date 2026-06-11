#include<iostream>
using namespace std;
#define FOR(xxx,begin,num) for(int xxx = (begin);xxx < ((begin) + (num)); xxx++)
#define MIN(a,b) (((a)<(b))?(a):(b))
typedef long long ll;
int main(){
  int k,q;
  ll d[5010],n[5010],x[5010],m[5010],Am[5010],Dd[5010];
  cin >> k >> q;
  FOR(i,0,k) cin >> d[i];
  FOR(i,0,q) cin >> n[i] >> x[i] >> m[i];
  FOR(i,0,q){
    ll smcase=0, eqcase=0, A = x[i];
    FOR(j,0,k) Dd[j] = d[j] % m[i];
    FOR(j,0,k){
      if(Dd[j] == 0) eqcase += (( (n[i]-1)%k<=j )?( (n[i]-1)/k ):( (n[i]-1)/k + 1 ));
      A += Dd[j] * (( (n[i]-1)%k<=j )?( (n[i]-1)/k ):( (n[i]-1)/k + 1 ));
    }
    smcase = (A) / m[i] - x[i] / m[i];
    cout << (n[i] - 1 - smcase - eqcase ) << endl;
  }
  return 0;
}