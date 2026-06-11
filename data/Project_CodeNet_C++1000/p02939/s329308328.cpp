#include<bits/stdc++.h>
#define all(v) v.begin(),v.end()
using namespace std;
int main(){
	string s;
	cin>>s;
	int ans=0,sz=2;
	for(int i=0;i<s.size();i++){
		if(sz==2){
			ans++;
			sz=1;
		}
		else{
			if(s[i]==s[i-1]){
				i++;
				if(i>=s.size()){
					break;
				}
				ans++;
				sz=2;
			}
			else{
				ans++;
				sz=1;
			}
		}
	}
	cout<<ans<<endl;
	return(0);
}