#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(){
	ll n,a,b,c,d;
	string s;
	cin>>n>>a>>b>>c>>d>>s;
	if((b<c&&c<d)||c<b){
		ll cnt=0;
		for(int i=b-1;i<d;i++){
			if(s[i]=='#'){
				cnt++;
				if(cnt>=2){
					cout<<"No";
					return 0;
				}
			}else cnt=0;
		}
		cnt=0;
		for(int i=a-1;i<c;i++){
			if(s[i]=='#'){
				cnt++;
				if(cnt>=2){
					cout<<"No";
					return 0;
				}
			}else cnt=0;
		}
	}
	if(d<c){
		ll cnt=0;
		bool f=0;
		for(int i=b-2;i<=d;i++){
			if(s[i]=='.'){
				cnt++;
				if(cnt>=3){
					f=1;
				}
			}else cnt=0;
		}
		if(!f){
			cout<<"No";
			return 0;
		}
		cnt=0;
		for(int i=a-1;i<c;i++){
			if(s[i]=='#'){
				cnt++;
				if(cnt>=2){
					cout<<"No";
					return 0;
				}
			}else cnt=0;
		}
	}
	cout<<"Yes";
	return 0;
}
