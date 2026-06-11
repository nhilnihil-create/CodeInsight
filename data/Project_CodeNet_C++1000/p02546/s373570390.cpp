#include<bits/stdc++.h>
#include<cstring>
// #include<queue>
#include<vector>
#include<utility>
using namespace std;
int inf=1e9;
//vector<long long int>adj[10000];

int main()
{
	int t;
	string str;
	cin>>str;
	int l=str.size();
	if(str[l-1]=='s')
	{
		cout<<str<<"es"<<endl;
	}
	else
	{
		cout<<str<<"s"<<endl;
	}
	return 0;
}
