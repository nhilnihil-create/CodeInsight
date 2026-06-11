#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<map>
#include<set> 
#include<string>
#include<stack>
#include<queue>
#include<vector>
#include<math.h>
using namespace std;
typedef long long ll;
int main()
{
	ll a,b,c,d;
	cin>>a>>b>>c>>d;
	ll s1,s2,s3,s4;
	s1=a*c;s2=a*d;s3=b*c;s4=b*d;
	ll max1=max(s1,s2);
	ll max2=max(s3,s4); 
	if(max1>=max2)
		cout<<max1<<endl;
	else
		cout<<max2<<endl;
	return 0;
}
