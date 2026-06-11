#include <bits/stdc++.h>
using namespace std;

int main()
{
  int64_t n,m;
  cin >> n >> m;
  
  int64_t h[n+1];
  for(int i = 1; i <= n; i++){
    cin >> h[i];
  }
  
  int64_t a[m+1],b[m+1];
  for(int i = 1; i <= m; i++){
    cin >> a[i] >> b[i];
  }
  
  int peek[n+1];
  for(int i = 1; i <= n; i++){
    peek[i] = 1;
  }
  
  for(int i = 1; i <= m; i++){
    if(h[a[i]] > h[b[i]]){
      peek[a[i]] *= 1;
      peek[b[i]] = 0;
    }else if(h[a[i]] == h[b[i]]){
      peek[a[i]] = 0;
      peek[b[i]] = 0;
    }else{
      peek[a[i]] = 0;
      peek[b[i]] *= 1;
    }
  }
  
  int ans = 0;
  for(int i = 1; i <= n; i++){
    if(peek[i] == 1){
      ans++;
    }
  }//for
  
  cout << ans << endl;  
  
}