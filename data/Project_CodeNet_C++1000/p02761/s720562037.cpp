#include <bits/stdc++.h>
using namespace std;
#include<cstdlib>

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
typedef long long ll;

int main(){
  int n,m;
  cin >> n >> m;

  vector<int> s(m);
  vector<int> c(m);
  rep(i,m){
    cin >> s.at(i) >> c.at(i);
  }

  int ans = -1;
  
  rep(i,1000){
    {
      int keta=0;
      int now = i;
      while(now>0){
        now/=10;
        keta++;
      }
      if(i==0) keta=1;
      if(keta!=n) continue;
    }
    
    {
      string now = to_string(i);
      bool check=true;
      rep(j,m){
        int keta=s.at(j)-1;
        if((now.at(keta)-'0')!=c.at(j)) {check=false; continue;}
      }
      if(!check) continue;
    }

    ans = i;
    break;
  }

  cout << ans;
}