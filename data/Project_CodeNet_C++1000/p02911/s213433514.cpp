#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=1;i<=(n);i++)
typedef long long ll;
ll a[100009];

int main() {
	ll i,n,t,k,j,x=0,y=0,m;
  	cin>>n >>k >>m;
  	for(i=1;i<=m;i++){
    	cin >> x;
      	a[x]++;
    }
  for(i=1;i<=n;i++){
  	y=m-a[i];
    a[i]=-y;
    a[i]+=k;
  	
  }
  
  for(i=1;i<=n;i++){
  	if(a[i]>0)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
  }
}