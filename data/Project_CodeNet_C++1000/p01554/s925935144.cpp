#include<iostream>
#include<string>
using namespace std;
int main()
{
	int n,m; cin>>n;
	string id[n];
	for(int i = 0; i < n; ++i)
	{
		cin>>id[i];
	}
	cin>>m;
	bool isOpen=false;
	for(int i = 0; i < m; ++i)
	{
		string in; cin>>in;
		bool out=false;
		for(int j = 0; j < n; ++j)
		{
			if(in==id[j])
			{
				if(!isOpen) cout<<"Opened by "<<in<<endl;
				else cout<<"Closed by "<<in<<endl;
				isOpen=!isOpen;
				out=true;
				break;
			}
		}
		if(!out) cout<<"Unknown "<<in<<endl;
	}
  return 0;
}