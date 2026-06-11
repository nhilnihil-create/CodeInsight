#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	char s[101]={};
	cin>>s;
	int l=strlen(s);
	bool c=true;
	for(int i=0; i<l; i++){
		if(s[i]!='U' && s[i]!='D'){
			if(i%2==0){
				if(s[i]!='R'){
						c=false;
				}
			}else{
				if(s[i]!='L'){
					c=false;
				}
			}
		}
	}
	if(c){
		cout<<"Yes"<<endl;
	}else{
		cout<<"No"<<endl;
	}
}