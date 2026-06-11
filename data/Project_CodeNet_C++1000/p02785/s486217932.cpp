#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
typedef long long ll;

int main() {
	int n,k;
  	cin>>n>>k;
  
  	vector <int> h(n);
  	rep(i,n)cin>>h[i];
  
  sort(h.begin(),h.end());
  reverse(h.begin(),h.end());
  
  ll ans=0;
  
  for(int i=0+k;i<n;i++){
  	while(h[i]>0){
    	ans++;
      	h[i]--;
    }
  }
  
  cout<<ans<<endl;
}