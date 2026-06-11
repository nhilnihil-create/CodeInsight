#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+233;

char s[maxn],t[maxn];

int main(){
	cin>>s>>t;
	int ans = maxn;
	int n1=strlen(s);
	int n2=strlen(t);
	for(int i=0;i+n2<=n1;i++){
		int sum = 0;
		for(int j=0;j<n2;j++){
			if(s[j+i]!=t[j]) sum++;
		}
		ans = min(ans,sum);
	}     
	cout<<ans<<endl;
}