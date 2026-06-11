#include<bits/stdc++.h>

using namespace std;

#define N 666666
char str[N];
map<int,int> mp;
signed main(){
	scanf("%s",str+1);
	int ans=1;
	int n=strlen(str+1); 
	int add=1;
	for(int i=2;i<=n;i++){
		if(str[i]!=str[i-1]||mp[i-1]){
			//add=1;
		}else{	
			i++;
			if(i>n) break;
			mp[i]=1;
		}
		ans++;
	}cout<<ans;
	return 0;
}