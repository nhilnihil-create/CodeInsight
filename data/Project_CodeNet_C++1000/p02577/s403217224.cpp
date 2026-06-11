#include<bits/stdc++.h>
using namespace std;
#define js ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
typedef long long ll;
char s[200005];
int main(){
	ll sum=0;
	scanf("%s",s);
	for(int i=0;i<strlen(s);i++){
		sum+=(s[i]-'0')%9;
	}
	if(sum%9==0){
		cout<<"Yes"<<endl;
	}else{
		cout<<"No"<<endl;
	}
	return 0;
} 