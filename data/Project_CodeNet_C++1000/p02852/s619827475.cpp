//============================================================================
// Name        : f.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main() {
	int n,m;cin>>n>>m;
	string s;cin>>s;
	reverse(s.begin(),s.end());
	vector<string> v(n);
	int temp=0;
	vector<int> ans;
//	cout<<s<<endl;
	while(temp<n){
		int flag=1;
		for(int i=m;i>=1;i--){
			if(temp+i>n)continue;
//			cout<<s[temp+i]<<endl;
			if(s[temp+i]=='0'){
				flag=0;
				temp+=i;
				ans.push_back(i);
				break;
			}
		}
		if(flag){
			cout<<-1<<endl;
			return 0;
		}
	}
	reverse(ans.begin(),ans.end());
	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<' ';
	}cout<<endl;
	return 0;
}
