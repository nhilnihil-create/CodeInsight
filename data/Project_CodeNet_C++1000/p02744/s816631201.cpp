#include <bits/stdc++.h>
using namespace std;

vector<string>ans;
string cur = "";
int n;

void solve(char c,int idx,char mx)
{
	if(idx==n-1){
		cur += c;
		ans.push_back(cur);
		cur.pop_back();
		return;
	}
	cur += c;
	for(char i='a';i<=mx+1;i++){
		solve(i,idx+1,max(mx,i));
	}
	cur.pop_back();
}
int main()
{
	cin >> n;
	solve('a',0,'a');
	sort(ans.begin(),ans.end());
	for(auto it:ans){
		cout << it << "\n";
	}
}
