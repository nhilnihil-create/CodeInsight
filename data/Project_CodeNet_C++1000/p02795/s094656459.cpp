#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;


int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	if(c%max(a,b))cout<<c/max(a,b)+1<<endl;
	else cout<<c/max(a,b)<<endl;
	return 0;
}