#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int,int> P;

int main(){
	string s;
	cin>>s;
	if(s.size()==2&&s[0]==s[1]){
		cout<<1<<endl;
		return 0;
	}
	int ans=s.size();
	for(int i=1;i<s.size();i++){
		if(s[i]==s[i-1])ans--,i+=2;
	}
	cout<<ans<<endl;
	return 0;
}
