#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	char s[n]={};
	cin>>s;
	int k=strlen(s);
	char d=s[0];
	int ans=1;
	for(int i=0; i<k; i++){
		if(d!=s[i]){
			ans++;
			d=s[i];
		}
	}
	cout<<ans<<endl;
}