#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;	cin >> n;
  vector<int>	p(n);
  for(int i=0;i<n;i++){
    cin >> p.at(i);
  }
  
  vector<int> mi(n);
  int m=n;
  for(int i=0;i<n;i++){
    m=min(m,p.at(i));
    mi.at(i)=m;
  }
  
  int ans=0;
  for(int i=0;i<n;i++){
    if(p.at(i)>mi.at(i))	continue;
    ans++;
  }
  cout << ans;
}