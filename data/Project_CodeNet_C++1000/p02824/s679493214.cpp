#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long int ll;

int main()
{
  int n, m, v, p;
  cin >> n >> m >> v >> p;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  //降順
  sort(a.begin(), a.end(), greater<int>());
  
  int ans = 0;
  //二分探索
  int ok = 0, ng = n;
  while(abs(ok - ng) > 1)
  {
    int mid = (ok + ng) / 2;
    bool flag = true;
    //check関数
    [&]
    {
      //全員mid問目に投票する。その結果、上位p問に入らないならfalse
      int aa = a[mid] + m;
      if(aa < a[p - 1])
      {
        flag = false;
        return;
      }
      
      //上位p問には全員投票する（mid含む）
      int vv = v - p;
      if(vv <= 0) return;
      
      //残った票をp+1問目以降の問題に貪欲に割り振っていく
      ll sum = m;
      sum *= vv;
      for(int i = p - 1; i < n; i++)
      {
        if(i == mid) continue;
        sum -= min((aa - a[i]), m);
        if(sum <= 0) return;
      }
      
      //票が残ったならfalse
      if(sum > 0) flag = false;
    }();
    
    if(flag) ok = mid;
    else ng = mid;
    
  }
  cout << ok + 1 << endl;
  
  return 0;
}