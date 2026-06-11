#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int main(){
	string s;
	cin>>s;
	int c=0;
	int ans=0;
	for(int i=0;i<3;i++){
		if(s[i]=='R'){
			c++;
		}else{
			ans=max(ans,c);
			c=0;
		}
	}
    ans=max(ans,c);
	cout<<ans<<endl;
}