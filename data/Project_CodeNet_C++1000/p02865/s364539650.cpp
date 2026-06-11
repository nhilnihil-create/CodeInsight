#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,total=0;
	cin>>n;
	for(int i=1;i*2<n;i++)
		total++;
		cout<<total<<endl;
		return 0;
}