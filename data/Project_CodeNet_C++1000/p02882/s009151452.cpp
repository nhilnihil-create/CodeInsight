#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef pair<int,int> P;
typedef long long ll;
const int INF = 1001001001;
const ll INFL = 1e17;
const int MOD = 1e9+7;


int main(){
    double a,b,x;
    cin >> a >> b >> x;
    double half = a*a*b/2.0;
    double now;
    if(x > half){
        now = 2.0/a*(b-x/a/a);
    }
    else{
        now = a*b*b/2.0/x;
    }
    printf("%.12lf\n",atan(now)*180.0/M_PI);
    return 0;
}