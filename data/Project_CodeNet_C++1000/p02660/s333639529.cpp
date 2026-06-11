#include<bits/stdc++.h>
using namespace std;
vector<long long>v;
int f(int x)
{
	int ans=0;
	for(int i=1;i<=100;i++)
	{
		ans+=i;
		if(ans>x)
		{
			return i-1;
		 } 
	}	
}
int main()
{
	int ans=0;
    long long x;
    cin>>x;if(x==1)
    {
    	cout<<"0"<<endl;
    	return 0;
	}
    for(int i=2;i<=sqrt(x);i++)
    {
        while(x%i==0)
        {
            x/=i;
            v.push_back(i);
        }
    }
    if(x>1)
    {
    	v.push_back(x);
	}
	int count1=1;
	for(int i=1;i<v.size();i++)
	{
		if(v[i]!=v[i-1])
		{
			//cout<<count1<<endl;
			ans+=f(count1);
			count1=1;
		}
		else
		{
			count1++;
		} 
	}
//	cout<<count1<<endl;
	if(count1)ans+=f(count1);
	cout<<ans;
    return 0;
}