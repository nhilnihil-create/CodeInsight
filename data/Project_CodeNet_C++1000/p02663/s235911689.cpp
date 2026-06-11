#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a,b,c,d,k,x=0;
    cin>>a>>b>>c>>d>>k;
    if(d>b)
    {
    	d-=b;
    	b=0;
    	x+=(c-a)*60;
    	x+=d;
    	x-=k;
	}
	else if(b>d)
	{
		b-=d;
		d=0;
		x=60-b;
		c--;
		x+=(c-a)*60;
		x-=k;
	}
	else
	{
		x+=(c-a)*60;
		x-=k;
	}
	cout<<x<<endl;
	return 0;
}

