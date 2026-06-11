#include<bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
typedef long long ll;

int main(){
	int n; cin>>n;
	int l[n];
	rep(i,n) cin>>l[i];
	sort(l,l+n);
	int ans=0;
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			for(int k=j+1; k<n; k++){
				if(l[i]!=l[j] && l[j]!=l[k] && l[i]!=l[k] 
				&& l[k]<l[i]+l[j]){
					ans++;
					//cout<<l[k]<<" "<<l[i]<<" "<<l[i]<<endl;
					
				}
				//cout<<l[k]<<" "<<l[j]<<" "<<l[i]<<endl;
			}
		}
	}
	cout<<ans<<endl;
}
		