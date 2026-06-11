#include<bits/stdc++.h>
#define rep(i,n) for(int i=0; i< (n); i++)
using namespace std;
typedef long long ll;
const int mod = 1000000007;

int main(){
	char s[2*100000+1]={};
	char t[2*100000+1]={};
	cin>>s>>t;
	int p=strlen(s);
	int ans=0;
	rep(i,p){
		if(s[i]!=t[i]){
			ans++;
		}
	}
	cout<<ans<<endl;
}