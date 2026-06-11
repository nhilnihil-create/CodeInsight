#include <iostream>
#include <cstdio>
#include <utility>
#include <vector>
#include <algorithm>
#define REP(i,n) for(int i=0;i<(n);i++)
using namespace std;

typedef pair<int,int> pii;

int main()
{
  while(1){
    int n;
    scanf("%d", &n);
    if(n == 0) break;
    vector<pii> time(n);
    REP(i,n){
      int h, m, s;
      scanf("%d:%d:%d", &h, &m, &s);
      time[i].first = h*3600 + m*60 + s;
      scanf("%d:%d:%d", &h, &m, &s);
      time[i].second = h*3600 + m*60 + s;
    }
    sort(time.begin(),time.end());
    int ans = 1;
    int t = 1;
    vector<int> f;
    REP(i,n){
      if(!f.empty())
        REP(j,(int)f.size())
          if(f[j] <= time[i].first){
            t++;
            f.erase(f.begin()+j);
          }
      if(t > 0){
        t--;
        f.push_back(time[i].second);
      }else{
        ans++;
        f.push_back(time[i].second);
      }
    }
    cout << ans << endl;
  }
}