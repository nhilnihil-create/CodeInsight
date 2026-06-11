#include <bits/stdc++.h> 
using namespace std;
int main()
{
	long long int a, b, c, k;
	cin>>a>>b>>c>>k;
	long long int m_sum;
	if(k<=a)
	{
		m_sum=k;
	}
	else if(k>a&&k<=a+b)
        {
               m_sum=a;
        }
else
	{
		m_sum=(2*a)+b-k;
	}
	cout<<m_sum<<endl;
	return 0;
}