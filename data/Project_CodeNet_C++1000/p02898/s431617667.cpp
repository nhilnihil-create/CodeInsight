#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int n,k,a=0;
	cin>>n>>k;
	std::vector<int> v(n,0);
	for (int i = 0; i < n; ++i)
	{
		cin>>v[i];
		if(v[i]>= k){
			a++;
		}
	}
	cout<<a<<endl;
	return 0;
}