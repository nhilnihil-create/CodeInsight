#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	ll n,rgb[3][4005]={};
	cin>>n;
	string s;
	cin>>s;
	for(ll i=0;i<n;i++){
		if(s[i]=='R'){
			rgb[0][i]=1;
		}
		else if(s[i]=='G'){
			rgb[1][i]=1;
		}
		else{
			rgb[2][i]=1;
		}
	}
	for(ll i=1;i<n;i++){
		for(ll j=0;j<3;j++){
			rgb[j][i]=rgb[j][i]+rgb[j][i-1];
		}
	}
	ll cnt=0;
	for(ll i=0;i<n;i++){
		for(ll k=i+2;k<n;k++){
			ll j;
			if((k+1+i+1)%2==0){
			j=(k+1+(i+1))/2;
			j--;
			}
			else{
				j=inf;
			}
			if(s[i]==s[k]){
				continue;
			}
			ll now=0;
			char ch;
			if(s[i]!='R'&&s[k]!='R'){
				now=0;
				ch='R';
			}
			else if(s[i]!='G'&&s[k]!='G'){
				now=1;
				ch='G';
			}
			else{
				now=2;
				ch='B';
			}
			cnt+=rgb[now][k-1]-rgb[now][i];
			if(j!=inf){
	//			cout << s[j]<<" ";
			}
	//		cout << cnt<<" "<< i<<" "<< j<<" "<<k<<" "<<ch<<endl;
			if(j==inf){
				continue;
			}
				if(ch==s[j]){
			//		cout << "k";
					cnt--;
				}
	//		cout << cnt<<endl;
		}
	}
	cout <<cnt;
	// your code goes here
	return 0;
}