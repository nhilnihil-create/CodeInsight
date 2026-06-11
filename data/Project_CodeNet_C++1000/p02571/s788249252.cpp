#include <bits/stdc++.h>
using namespace std;
       
int main()
{
	int ans=0,mn=123456789;
	string s,ss,s1;
  	cin>>s>>ss;
 	for(int i=0;i<s.size()-ss.size()+1;i++){
 		s1=s.substr(i,ss.size()); 
 		for(int j=0;j<ss.size();j++){
 			if(s1[j]!=ss[j])
 				ans++;	
		}
		if(ans<mn){
			mn=ans;
		}
		ans=0;
	}
	cout<<mn;
	return 0;
}