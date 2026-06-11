#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, m;
  string s;
  cin >> n >> m >> s;
  vector<bool> bo(n+1);
  for(int i=0; i<=n; ++i){
    if(s[i]-'0') bo[i] = true;
    else bo[i] = false;
  }
  vector<int> ans(0);
  int posi = n;
  while(posi > 0){
    bool ansis = false;
    for(int i = max(0,posi-m); i<posi; ++i){
      //cout << posi << " " << i << ':' << bo[i] << endl;
      if(!bo[i]){
        ansis = true;
        ans.push_back(posi-i);
        posi = i;
        break;
      }
    }
    if(!ansis){
      cout << -1 << endl;
      return 0;
    }
  }
  for(int i=ans.size()-1; i>=0; --i){
    if(i==0) printf("%d\n",ans[i]);
    else printf("%d ",ans[i]);
  }
}