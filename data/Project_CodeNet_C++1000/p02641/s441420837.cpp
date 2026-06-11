#include<bits/stdc++.h>
using namespace std;
int main(){
  int x,n;
  cin >> x >> n;
  int h;
  map <long long, bool> ad;
  for(int i=0;i<n;i++){
    cin >> h;
    ad[h]=1;
  }
  int l,u,ans=0;
  l=u=x;
  while(1){
    if(ad[l])l--;
    else{ans=l;break;};
    if(ad[u])u++;
    else{ans=u;break;};
  }
  cout << ans << endl;
}