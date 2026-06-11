#include <iostream>
using namespace std;

int main()
{
	string s, t;
	int sum, minv=1001;
	getline(cin, s);
	getline(cin, t);
	for(int i=0; i<=s.size()-t.size(); ++i)
	{
		sum=0;
		for(int j=0; j<t.size(); ++j)
		{
			if(s[i+j]!=t[j])
			{
				sum++;
			}
		}
		if(minv>sum)
		{
			minv=sum;
		}
	}
	cout << minv << endl;
	return 0;
}