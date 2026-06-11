#include<bits/stdc++.h>

#define pb push_back
#define fi first
#define se second


using namespace std;

vector<int> v;

int main()
{
	
	int a,b;

	cin>>a>>b;

	v.pb(a);
	v.pb(b);


	sort(v.begin(), v.end());
	
	if(v[0]==2)
		cout<<1<<endl;
	else if(v[1] == 2)
		cout<<3<<endl;
	else
		cout<<2<<endl;


	return 0;
}
