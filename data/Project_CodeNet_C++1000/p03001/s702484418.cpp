#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod= int(1e9)+7;
using P = pair<int,int>;
using Pll = pair<ll,ll>;
using ld=long double;

int main(){
   ld w,h;cin >>w>>h;
   ld x,y;cin >>x>>y;
   int t=0;
   if(w/2==x&&h/2==y)t=1;
   ld ans=h*w/2;
   cout <<setprecision(20)<<ans<<" "<<t<<endl;
}
