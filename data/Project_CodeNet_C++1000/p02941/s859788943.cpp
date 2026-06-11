#include<iostream>
#include<vector>
using namespace std;
int n;
vector<long long> a,b;
long long B=0;
int main()
{
	cin>>n;
    a.resize(n,0);
	b.resize(n,0);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    while(true)
	{
        int change=0;
        for(int i=0;i<n;i++)
		{
            long long x=b[(n+i-1)%n],y=b[(n+i+1)%n];
            if(b[i]<x+y) continue;
            if(a[i]==b[i]) continue;
            change+=1;
            long long t=b[i]%(x+y);
            if(t<a[i])
			{
                long long p=b[i]-a[i];
                if(p%(x+y)!=0) B=-1;
                B+=p/(x+y);
                b[i]=a[i];
            }
            else
			{
                B+=b[i]/(x+y);
                b[i]=t;
            }
        }
        if(change==0||B==-1) break;
    }
    bool pos=true;
    for(int i=0;i<n;i++)
        if(a[i]!=b[i])
            pos=false;
    if(pos) cout<<B<<endl;
    else cout<<-1<<endl;
	return 0;
}