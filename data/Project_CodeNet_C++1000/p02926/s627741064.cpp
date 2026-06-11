#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 998244353;

signed main() {
  int n;
  cin>>n;
  double x,y;
  vector<pair<double,pair<double,double>>> p;
  for(int i=0;i<n;i++){
    cin>>x>>y;
  if(x!=0||y!=0)p.push_back(make_pair(atan2(y,x),make_pair(x,y)));
  }
  sort(p.begin(),p.end());
  int j=0;
  n=p.size();
  double X=0,Y=0;
  double ans=0;
  for(int i=0;i<n;i++){
    while((((p[j%n].first-p[i].first)>=0&&(p[j%n].first-p[i].first)<M_PI)||((p[j%n].first-p[i].first)<0&&(p[j%n].first-p[i].first)<-1*M_PI))&&j!=i+n){
      X+=(p[j%n].second).first;
      Y+=(p[j%n].second).second;
         ans=max(ans,sqrt(X*X+Y*Y));
      j++;
    }
 
    X-=(p[i].second).first;
      Y-=(p[i].second).second;
         ans=max(ans,sqrt(X*X+Y*Y));
  }
  cout<< std::fixed<< std::setprecision(50)<<ans;
  
  



  return 0;
}
