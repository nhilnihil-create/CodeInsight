#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
int main()
{

	fast;
	long long int a,b,c,p=0,q=0;
	cin>>a>>b>>c;
	p = a-b;
	q = c-p;
	if(q <=0){
		q = 0;
	}
	cout << q <<endl;
	return 0;
}

