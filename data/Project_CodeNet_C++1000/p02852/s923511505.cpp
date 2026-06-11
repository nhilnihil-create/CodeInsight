#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	int n,k;cin>>n>>k;
	string s;cin>>s;
	vector<int>ans;
	for(int i=s.size()-1;i>0;i--){
		int low=i;
		for(int j=i;j>=max(0,i-k);j--){
			if(s[j]=='0'){
				low=j;
			}
		}
		if(low==i){
			cout<<-1<<endl;
			return 0;
		}else{
			ans.push_back(i-low);
			i=low+1;
		}
	}
	reverse(ans.begin(),ans.end());
	for(auto u:ans){
		cout<<u<<' ';
	}cout<<endl;
	return 0;
}