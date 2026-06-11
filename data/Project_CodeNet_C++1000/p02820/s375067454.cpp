#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define mod 1000000007
void solve(){
	int n,k;
	cin>>n>>k;
	int a[3];
	for(int i=0;i<3;i++){
		cin>>a[i];
	}
	string s;
	cin>>s;
	int ans=0;
	for(int i=0;i<k;i++){
		for(int j=i;j<n;j+=k){
			ans+=((s[j]=='r')?a[2]:0)+((s[j]=='s')?a[0]:0)+((s[j]=='p')?a[1]:0);
			if(s[j]==s[j+k])
				j+=k;
		}
	}
	cout<<ans<<endl;
}

int main(){
    int t=1;
	//cin>>t;
    while(t--)
        solve();
}
