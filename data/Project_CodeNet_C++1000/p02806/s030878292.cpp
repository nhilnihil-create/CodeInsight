#include<bits/stdc++.h>
using namespace std;
struct node
{
    string s;
    int t;
}ans[111];
int main()
{
	ios::sync_with_stdio(false);
	string x;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
    {
        cin>>ans[i].s>>ans[i].t;
    }
    cin>>x;
    int flag=0,sum=0;
    for(int i=1;i<=n;i++)
    {
        if(ans[i].s==x)
            {
                flag=i;
                break;
            }
    }
    for(int i=flag+1;i<=n;i++)
    {
        sum+=ans[i].t;
    }
    cout<<sum<<endl;
	return 0;
}
