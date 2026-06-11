//============================================================================
// Name        : e.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int main() {
	string s,t;cin>>s>>t;
	vector<vector<int>> a(26);
	for(int i=0;i<s.size();i++){
		a[s[i]-'a'].push_back(i);
	}
	long long ans=-1;
	for(int i=0;i<s.size();i++){
		if(s[i]==t[0]){
			ans=i;
			break;
		}
	}
//	cout<<s<<t<<ans<<endl;
	if(ans==-1){
		cout<<-1<<endl;
		return 0;
	}
	for(int i=1;i<t.size();i++){
		vector<int> v;
//		v=a[t[i]-'a'];
		if(a[t[i]-'a'].size()==0){
			cout<<-1<<endl;
			return 0;
		}
//		for(int j=0;j<v.size();j++){
//			cout<<v[j]<<' ';
//		}cout<<endl;
		int idx=upper_bound(a[t[i]-'a'].begin(),a[t[i]-'a'].end(),ans%s.size())-a[t[i]-'a'].begin();
		if(idx==a[t[i]-'a'].size()){
			ans=((ans)/s.size()+1)*s.size()+a[t[i]-'a'][0];
		}else{
			ans+=a[t[i]-'a'][idx]-ans%s.size();
		}
//		cout<<idx<<' '<<ans<<endl;
	}
	cout<<ans+1<<endl;
	return 0;
}