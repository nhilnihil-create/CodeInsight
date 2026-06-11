#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[1001];
    bool flag=1;
    for(int i=1;i<=n;i++)
    	cin>>a[i];
    for(int i=1;i<=n;i++)
    {
    	if(a[i]%2==1)continue;
    	else if(a[i]%3!=0&&a[i]%5!=0)flag=0;
	}
	if(flag)cout<<"APPROVED";
	else cout<<"DENIED";
    return 0;
} 