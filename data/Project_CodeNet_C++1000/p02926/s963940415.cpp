#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  vector<tuple<long double,ll,ll>> cor(n);
  rep(i,n){
    long double x,y;
    cin >> x >> y;
    long double ang = atan2(y,x);
    cor[i] = make_tuple(ang,x,y);
  }

  sort(cor.begin(),cor.end());
  rep(i,n){
    cor.pb(make_tuple(get<0>(cor[i])+2*M_PI, get<1>(cor[i]), get<2>(cor[i])));
  }

  long double eps=1e-12;
  long double ans=0;
  rep(i,n){
    long double st = get<0>(cor[i]);
    int ed_idx = i;    
    long double x = get<1>(cor[i]);
    long double y = get<2>(cor[i]);
    while(get<0>(cor[ed_idx+1]) - st < M_PI+eps){
      ans = max(ans,sqrt(x*x+y*y));
      ed_idx++;
      x+=get<1>(cor[ed_idx]);
      y+=get<2>(cor[ed_idx]);      
    }
    //    cout << "stidx edidx len " << i << " " << ed_idx << " " << sqrt(x*x+y*y) << endl; 
    ans = max(ans,sqrt(x*x+y*y));
    
  }
  cout << fixed << setprecision(12) << ans << endl;
    
  

  return 0;
    

}
