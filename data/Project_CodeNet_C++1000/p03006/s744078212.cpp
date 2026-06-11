#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

ll a[52],b[52];
int main() {
	ll n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
	}
	ll ans=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i==j){
				continue;
			}
			ll sum=0;
			ll nowx=a[j]-a[i];
			ll nowy=b[j]-b[i];
			for(int k=0;k<n;k++){
				for(int l=0;l<n;l++){
					if(k==l){
						continue;
					}
					ll nex=a[l]-a[k];
					ll ney=b[l]-b[k];
					if(nowx==nex&&nowy==ney){
						sum++;
					}
				}
			}
			ans=max(ans,sum);
		}
	}
	cout << n-ans;
	// your code goes here
	return 0;
}