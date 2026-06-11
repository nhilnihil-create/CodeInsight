#include<bits/stdc++.h>
using namespace std;
long long int n,a[200005],cnt[200005],p[200005];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
	    cin>>a[i];
	    if(i>a[i]){
	        cnt[i-a[i]]++;
	    }
	}
	for(int i=1;i<=n;i++){
	    if(i+a[i]<=2e5){
	        p[i+a[i]]++;
	    }
	}
	long long ans=0;
	for(int i=1;i<=2e5;i++){
	    ans+=cnt[i]*p[i];
	}
	cout<<ans;
}
