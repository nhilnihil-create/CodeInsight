#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(v) v.begin(),v.end()
#define len(x) (ll)(x).length()
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int INF=1e9;
const int di[] = {-1,0,1,0};
const int dj[] = {0,-1,0,1};

int main() {
    double a,b,x;
    cin>>a>>b>>x;
    double s=x/a;
    double rad;
    if(s>=a*b/2){
      double h=(a*b-s)*2/a;
      rad = atan(h/a);
    }else{
      double w =s*2/b;
      rad = atan(b/w);
    }
    double PI = acos(-1);
    double deg = rad/(2*PI)*360;
    printf("%.10f\n",deg);
}