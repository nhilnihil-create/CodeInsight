#include<bits/stdc++.h>
using namespace std;
string s,t;
     int ms(string a,string b){
		 int c=0;
		 for(int i=0;i<a.size();i++){
			 if(a[i]!=b[i])
				 c++;
		 }
		 return c;
	 }
	void solve(){
		int ans=1e9;
		cin>>s>>t;
		for(int i=0;i+t.size()<=s.size();i++){
			ans=min(ans,ms(s.substr(i,t.size()),t));
		}
		cout<<ans;
	}
int main(){
	solve();
}
