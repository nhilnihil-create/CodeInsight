#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	int n;
	cin>>n;
	char s[n+1]={};
	cin>>s;
	if(n%2==1){
		cout<<"No"<<endl;
	}else{
		int k=n/2;
		bool c=true;
		for(int i=0; i<k; i++){
			if(s[i]!=s[k+i]){
				c=false;
			}
		}
		if(c){
			cout<<"Yes"<<endl;
		}else{
			cout<<"No"<<endl;
		}
	}
}