#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
    cin>>n>>m;
    int ans=n;
    for(int i=0;i<m;i++){
    	int a; cin>>a;
        ans-=a;
    }
  if(ans>=0) cout<<ans;
  else cout<<"-1";
}
