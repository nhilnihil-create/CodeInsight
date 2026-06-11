#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(v) v.begin(),v.end()
#define len(x) (ll)(x).length()
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int INF=1e9;
const ll INFS=1e18;
const int di[] = {-1,0,1,0};
const int dj[] = {0,-1,0,1};
 
int main() {
  double a,b,x;
  cin>>a>>b>>x;
  double s=x/a;
  double rad;
  double deg;
  if(s>=a*b/2){
    double h=2*(a*b-s)/a;
    double PI=acos(-1);
    rad=atan2(h,a);
  }else{
    double w=s*2/b;
    double PI=acos(-1);
    rad=atan2(b,w);
  }
  double PI=acos(-1);
    deg=(rad/(2*PI))*360;
  printf("%.10f\n",deg);
}