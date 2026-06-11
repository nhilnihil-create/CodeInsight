#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int c=0,f=0;
	while(n--)
	{
	    int a,b;
	    cin>>a>>b;
	    if(a==b)
	    {
	        c++;
	        if(c>=3)
	        {
	            f=1;
	        }
	    }
	    else
	    {
	     c=0;   
	    }
	}
	if(f==1)
	cout<<"Yes";
	else
	cout<<"No";
}