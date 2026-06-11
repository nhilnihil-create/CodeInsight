#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,k,c;
	string s;
	cin>>n>>k>>c>>s;
	vector<int> early;
	vector<int> late;
	int tmp=-1e9;
	for (int i=0;i<n;i++){
		if (i>tmp+c&&s[i]=='o'&&early.size()<k){
			tmp=i;
			early.push_back(i);
		}
	}
	tmp=1e9;
	for (int i=n-1;i>=0;i--){
		if (i<tmp-c&&s[i]=='o'&&late.size()<k){
			tmp=i;
			late.push_back(i);
		}
	}
	reverse(late.begin(),late.end());
	for (int i=0;i<k;i++)
		if (late[i]==early[i])
			cout<<late[i]+1<<endl;
	return 0;
}