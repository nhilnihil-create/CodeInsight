
#include <bits/stdc++.h>
using namespace std;
const int maxn=200000+10;
int n,m;
int a[maxn],f[maxn],INF,du[maxn],ans;
bool v[maxn];
char s[maxn];
int main(){
	cin>>n>>m;
	scanf("%s",s+1);
	int l=2,r=n;
	while(l<=n){
		if(s[l]==s[l-1]){
			l++; continue;
		}
		else{
			l++;
			int tmp1=l-1;
			while(s[l]==s[l-1]) l++;
			for(int i=tmp1; i<l; i++){
				if(s[i]=='L') s[i]='R';
				else s[i]='L';
			}
			l++;
			m--;
			if(m==0) break;
		}
	}
	for(int i=1; i<=n; i++){
		if(s[i]==s[i-1]) ans++;
	}
	cout<<ans<<endl;
	return 0;
} 