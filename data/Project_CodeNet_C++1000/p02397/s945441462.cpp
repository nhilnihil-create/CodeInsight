#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	vector<int> n,m;
	int a,b,co=0;
	while(1)
	{
		cin>>a>>b;
		if(a==0&&b==0)break;
		n.push_back(min(a,b));
		m.push_back(max(a,b));
		co++;
	}
	for(a=0;a<co;a++)
	{
		cout<<n[a]<<" "<<m[a]<<endl;
	}
	return 0;
}