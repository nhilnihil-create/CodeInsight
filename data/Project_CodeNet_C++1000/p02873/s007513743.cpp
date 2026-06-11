#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=1e6+233;

char s[maxn];

ll f[maxn];

int main(){
    
    cin>>s;
    int n = strlen(s);
    for(int i=0;i<n;i++){
    	if(s[i]=='<') f[i+1] = f[i]+1;
	}
	for(int i=n-1;i>=0;i--){
		if(s[i]=='>') f[i] = max(f[i],f[i+1]+1);
	}
	ll ans = 0;
	for(int i=0;i<=n;i++) ans+=f[i];
	cout<<ans<<endl;
    
    return 0;
}