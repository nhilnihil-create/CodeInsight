#include <bits/stdc++.h>
#define rep(i,m,n) for(int i=m;i<n;i++)
#define fix(n) cout<<fixed<<setprecision(n)
#define co(n) cout<<n<<endl
#define all(n) (n).begin(),(n).end()
using namespace std;
typedef long long ll;
const ll mod=1000000007;
double pi=3.1415926535;

int main(){
  int m,d,a,b;
  cin>>m>>d;
  
  int c=0;
  if(m<4 || d<22) co(0);
  else{
    rep(i,4,m+1){
      rep(j,22,d+1){
        a=j/10;
        b=j%10;
        if(a>=2 && b>=2 && i==a*b){
          c++;
        }
      }
    }
    co(c);
  }
  
  return 0;
}