#include<bits/stdc++.h>
using namespace std;
int k;
void dfs(string ans,int p,int& now){
	if(p==0){
		now++;
		if(now==k){
			cout<<ans<<endl;
			exit(0);
		}
		return ;
	}
	int x=ans[ans.size()-1]-'0';
	for(int i=x-1;i<=x+1;i++){
		if(i<0||9<i)continue;
		dfs(ans+(char)(i+'0'),p-1,now);
	}
}
int main(){
	cin>>k;
	int now=0;
	for(int i=1;;i++){
		for(char c='1';c<='9';c++){
			string s="";
			s+=c;
			dfs(s,i-1,now);
		}
	}
	return 0;
}