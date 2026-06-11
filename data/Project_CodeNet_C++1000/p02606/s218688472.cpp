#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	//freopen("in.txt","t",stdin);
	int l,r,d;
	cin>>l>>r>>d;
	int cnt=0;

	while(l<=r)
	{
		if(l%d==0)
			cnt++;
		l++;
	}
	cout<<cnt<<endl;
	return 0;
}