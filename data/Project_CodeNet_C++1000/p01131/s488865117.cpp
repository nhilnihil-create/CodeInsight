#include<iostream>
#include<vector>
using namespace std;
vector<char>s[10];
main()
{
	string t;
	t=".,!? ";for(int i=0;i<t.size();i++)s[1].push_back(t[i]);
	t="abc";for(int i=0;i<t.size();i++)s[2].push_back(t[i]);
	t="def";for(int i=0;i<t.size();i++)s[3].push_back(t[i]);
	t="ghi";for(int i=0;i<t.size();i++)s[4].push_back(t[i]);
	t="jkl";for(int i=0;i<t.size();i++)s[5].push_back(t[i]);
	t="mno";for(int i=0;i<t.size();i++)s[6].push_back(t[i]);
	t="pqrs";for(int i=0;i<t.size();i++)s[7].push_back(t[i]);
	t="tuv";for(int i=0;i<t.size();i++)s[8].push_back(t[i]);
	t="wxyz";for(int i=0;i<t.size();i++)s[9].push_back(t[i]);
	int n;cin>>n;
	for(;n--;)
	{
		cin>>t;
		string ans="";
		for(int i=0;i<t.size();i++)
		{
			int cnt=0,c=t[i]-'0';
			while(t[i]!='0')cnt++,i++;
			if(cnt)ans+=s[c][(cnt-1)%s[c].size()];
		}
		cout<<ans<<endl;
	}
}

