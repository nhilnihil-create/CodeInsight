#include <bits/stdc++.h>
using namespace std;


int n,m;
string S,T;
int main()
{
	getline(cin,S);
	getline(cin,T);
	int ans = 1010;
	for(int i=0;i<=S.length()-T.length();i++)
	{
		int now = 0;
		for(int j=0;j<T.length();j++)
		{
			if(S[i+j]!=T[j])	now++;
		}
		ans = min(ans,now);
	
	}
	cout << ans << endl;
	return 0;
}