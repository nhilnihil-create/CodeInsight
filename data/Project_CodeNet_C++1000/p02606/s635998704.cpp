#include<bits/stdc++.h>
using namespace std;
#define ll  long long  

void solve(){
  int l ,r,d;
  cin>>l>>r>>d;
  int cnt =0;
  for (int i = l; i <= r; ++i)
  {
    if(i%d==0)cnt++;
  }
  cout<< cnt;
}

int main()
{
     ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

     int t=1; 
     // cin >> t;
     while (t--) solve();
 
     return 0;
}