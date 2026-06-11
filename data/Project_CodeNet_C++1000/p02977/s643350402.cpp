#include<bits/stdc++.h>
using namespace std;
int lowbit(int x) {return x&-x;}
int n;
void work() {
    for(int i=2;i+1<=n;i+=2)
	{
	    cout<<i+n+1<<' '<<i<<'\n';
	    cout<<i<<' '<<1<<'\n';
	    cout<<1<<' '<<i+1<<'\n';
	    cout<<i+1<<' '<<i+n<<'\n';
	}
    cout<<n+1<<' '<<n+2<<'\n';
    if(!(n&1))
	{
	    int x=1;
	    while(x+x<=n) x<<=1;
	    cout<<(x+1)<<' '<<n<<'\n';
	    cout<<(x^n)<<' '<<n+n<<'\n';
	}
}
int main()
{
    cin>>n;
    if(lowbit(n)==n) cout<<"No"<<'\n';
    else
	{
	    cout<<"Yes"<<'\n';
	    work();
	}
    return 0;
}