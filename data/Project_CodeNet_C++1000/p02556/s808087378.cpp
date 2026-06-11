#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[200005],n,b[200005];
const int mod=1e9+7;
int main(){
  
    cin>>n;
    for(int i=1;i<=n;i++){
    	int x,y;
    	cin>>x>>y;
    	a[i]=x-y;
    	b[i]=x+y;
    }
    sort(a+1,a+1+n);
    sort(b+1,b+1+n);
   ll ans=max(a[n]-a[1],b[n]-b[1]);
    cout<<ans;
	return 0;
}
