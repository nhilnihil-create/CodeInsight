#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,f,n) for(int i=f; i<(n); i++)
int main()
{
  double ans = 0;
  int n, cnt=0;
  cin >> n;
  vector<int> c;
  vector<pair<int, int>> a;
  REP(i,0,n){
    int x, y;
    c.push_back(i);
    cin >> x >> y;
    a.push_back({x, y});
  }
  do{
    cnt++;
    double cost = 0;
    int x = a[c[0]].first, y = a[c[0]].second;
    REP(i,1,n){
      //cout << "[" << x << "," << y << "]->";
      cost += sqrt((x-a[c[i]].first)*(x-a[c[i]].first)+(y-a[c[i]].second)*(y-a[c[i]].second));
      x = a[c[i]].first;
      y = a[c[i]].second;
    }
    //cout << "[" << x << "," << y << "]->";
    //cout << cost << endl;
    ans += cost;
  }while(next_permutation(c.begin(), c.end()));
  //cout << ans << ", " << cnt << endl;
  printf("%.10lf\n",ans/cnt);

  //--debug : end_stoper
  //string end_stoper; cin >> end_stoper;

  return 0;
}