#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
int main()
{	
	int n;
    cin>>n;
    while(n>1000)
    {
    	n=n-1000;
    }
    cout<<1000-n<<"\n";
    return 0;
}
