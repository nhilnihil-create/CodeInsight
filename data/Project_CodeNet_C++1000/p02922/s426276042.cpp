#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
	int a,b,count=1;
    cin>>a>>b;
    if(b==1)
    {
        cout<<0<<endl;
        return 0;
    }
    int ans=a;
	while(ans<b)
    {
        count++;
        ans+=a-1;
    }
    cout<<count;
}