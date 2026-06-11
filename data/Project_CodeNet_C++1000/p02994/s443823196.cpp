#include<bits/stdc++.h>
#define ll long long int 
using namespace std;

 

int main()
{ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,l;
    cin>>n>>l;
    int total=l*n+((n*(n+1))/2)-n;
    if(l>=0)
    {
    	cout<<total-l<<endl;
    }
    else
    {
    	if(abs(l)>=n)
    	{
    		cout<<total-(l+n-1)<<endl;
    	}
    	else
    	{
    		cout<<total<<endl;
    	}
    }
	return 0;

}
