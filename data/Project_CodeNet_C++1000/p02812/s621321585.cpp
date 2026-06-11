#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<stdio.h>
#include<map>
#include<queue>
#include<vector>
using namespace std;

typedef long long ll;

int main(){
	int n,ans=0;
	char s[55];
	cin>>n;
	for(int i=1;i<=n;i++) cin>>s[i];
	for(int i=1;i<=n;){
		if(s[i]=='A'&&s[i+1]=='B'&&s[i+2]=='C'){
			i+=3;
			ans++;
		}else{
			i++;
		}
	}
	cout<<ans;
	return 0;
}