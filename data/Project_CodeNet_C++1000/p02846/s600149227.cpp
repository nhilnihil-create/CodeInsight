#include <bits/stdc++.h>
#define ROOP(i, N) for(int i=0; i++; i<N)
#define RVROOP(i, N) for(int i=N; i--; i>=0)
#define INF 1e9
#define MOD 1000000007
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int main() {
  ll T1,T2,A1,A2,B1,B2;
  cin>>T1>>T2>>A1>>A2>>B1>>B2;
  ll p=(A1-B1)*T1, q=(A2-B2)*T2;
  if(p>0){
    p*=(-1);
    q*=(-1);
  }
  if(p+q<0){
    cout<<"0"<<endl;
  }
  else if(p+q==0){
    cout<<"infinity"<<endl;
  }
  else{
    ll S,T;
    S=-p/(p+q);
    T=-p%(p+q);
    if(T==0){
      cout<<2*S<<endl;
    }
    else{
      cout<<2*S+1<<endl;
    }
  }
}
