#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,x,t;
    cin>>n>>x>>t;
    for(int i=1;i>0;i++)
    {
        if(i*x>=n)
        {
            cout<<i*t;
            break;
        }
    }
	return 0;
}
