#include <bits/stdc++.h>
using namespace std;

int main() {
  long ans=0;
  string n;
  cin >> n;
  vector<int> nn(n.size());
  for(int i=0;i<n.size();i++) {
    nn[i]=n[i]-'0';
  }
  for(int i=n.size()-1;i>=0;i--) {
    if(i!=0) {
      if(nn[i-1]>4&&nn[i]==5) {
        ans+=5;
        nn[i-1]++;
        continue;
      }
    }
    if(nn[i]==10) {
      if(i==0) ans+=1;
      else nn[i-1]++;
    } else if(nn[i]<6) {
      ans+=nn[i];
    } else {
      if(i==0) {
        ans+=11-nn[i];
      } else {
        ans+=10-nn[i];
        nn[i-1]++;
      }
    }
  }
  cout << ans << endl;
}