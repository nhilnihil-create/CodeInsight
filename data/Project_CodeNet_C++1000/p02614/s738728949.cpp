#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int main(){
int h,w,k;
cin>>h>>w>>k;
int ans=0;
vector<string>s(h);
rep(i,h) cin>>s.at(i);
rep(is,1<<h) rep(js,1<<w){
	int cnt=0;
  	rep(i,h)rep(j,w){
      	//すべて消えるとき
    	if(is>>i & 1) continue;
      	if(js>>j & 1) continue;
      	if(s.at(i).at(j)=='#') cnt++;
    }
  if(cnt==k) ans++;
}
  cout<<ans<<endl;
}