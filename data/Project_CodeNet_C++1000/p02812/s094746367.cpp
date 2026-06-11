#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	int n,ans=0;
	cin>>n;
	char s[n+1];
	cin>>s;
	for(int i=0; i<=n-3; i++){
		if(s[i]=='A' && s[i+1]=='B' && s[i+2]=='C'){
			ans++;
		}
	}
	cout<<ans<<endl;
}