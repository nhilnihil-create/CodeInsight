#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD=1000000007;
const double PI=3.14159265358979;
const ll INF= pow(10,18);
typedef pair<ll,ll> P;
typedef vector<ll> vl;
typedef vector<vl> vvl;
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define rep(i,n) FOR(i,0,n)
string abc="abcdefghijklmnopqrstuvwxyz";
string ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main() {
  ll t1,t2,a1,a2,b1,b2;
  cin >> t1 >> t2 >> a1 >> a2 >> b1 >> b2;
  ll A=(t1*a1)+(t2*a2);
  ll B=(t1*b1)+(t2*b2);
  ll D,L;
  if(A==B){
    cout << "infinity" << endl;
  }
  else{
    if(A>B){
      if(a1>b1){
        cout << 0 << endl;
      }
      else{
        D=A-B;
        L=(b1-a1)*t1;
        if(L%D==0){
          cout << L/D*2 << endl;
        }
        else{
          cout << L/D*2+1 << endl;
        }
      }
    }
    else{
      if(b1>a1){
        cout << 0 << endl;
      }
      else{
          D=B-A;
          L=(a1-b1)*t1;
          if(L%D==0){
            cout << L/D*2 << endl;
          }
          else{
            cout << L/D*2+1 << endl;
        }
      }
    }
  }
}