#include<bits/stdc++.h>
using namespace std;

int n,m;
string s;
vector<int> ans;

int main()
{
	cin>>n>>m>>s;
	int j;
	for(int i=n;i>0;i-=j) {
		for(j=m;j>0;--j) {
			if(i-j<0||s[i-j]=='1') continue;
			ans.push_back(j);
			break;
		}
		if(j==0) {
			printf("-1");
			return 0;
		}
	}
	for(int i=ans.size()-1;i>-1;--i) printf("%d ",ans[i]);
}