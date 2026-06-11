#include<bits/stdc++.h>
using namespace std;
int N;
vector<string>ans;
void find(string s,int var,char ch)
{
	if(var==0){
	 ans.push_back(s);
	 return ;
    }
	set<char>store;
	for(int i=0; i<N-var; i++){
		store.insert(s[i]);
	}
	string t=s+ch;
	find(t,var-1,ch+1);
	for(char letter : store){
		string p=s+letter;
		find(p,var-1,ch);
	}
}
int main()
{
	cin>>N;
	string s="";
	find(s,N,'a');
//	cout<<ans.size();
	sort(ans.begin(),ans.end());
	for(int i=0; i<ans.size(); i++)
	 cout<<ans[i]<<"\n";
	return 0;
}