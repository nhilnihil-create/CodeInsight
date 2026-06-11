#include <bits/stdc++.h>
using namespace std;
int main(){
  int n,m;	cin >> n >> m;
  vector<int> h(n);
  vector<bool>	ok(n,true);
  for(int i=0;i<n;i++){
    cin >> h.at(i);
  }
  
  for(int i=0;i<m;i++){
    int a,b;	cin >> a >> b;	a--;	b--;
    if(h.at(a)<=h.at(b))	ok.at(a)=false;
    if(h.at(b)<=h.at(a))	ok.at(b)=false;
  }
  int ans=0;
  for(bool f:ok){
    if(f)	ans++;
  }
  cout << ans;
}