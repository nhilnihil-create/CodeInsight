#include <bits/stdc++.h> 
using namespace std;
typedef long long intl;
int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n;
	cin>>n;
	string s;
	cin>>s;
	vector <int> evfact(n+2,0);
	for(int i=1;i<n+2;i++){
		int p=0;
		int aux=i;
		while(aux%2==0){
			aux/=2;
			p++;
		}
		evfact[i]=evfact[i-1]+p;
	}
	bool uno=false;
	for(int i=0;i<n;i++){
		if(s[i]=='2'){
			uno=true;
		}
	}
	if(uno){
		int ans=0;
		for(int i=0;i<n;i++){
			if(evfact[n-1]==evfact[n-1-i]+evfact[i]){
				ans+=(s[i]-'0');
			}
		}
		cout<<ans%2<<endl;
	}
	else{
		int ans=0;
		for(int i=0;i<n;i++){
			if(evfact[n-1]==evfact[n-1-i]+evfact[i]){
				if(s[i]=='3'){
					ans+=1;
				}
			}
		}
		if(ans%2==0){
			cout<<0<<endl;
		}
		else{
			cout<<2<<endl;
		}
	}
	
}
