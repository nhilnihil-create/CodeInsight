#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
int main()
{	
	//#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);  // for getting input from input.txt
    //freopen("output.txt", "w", stdout);	 // for writing output to output.txt	
	//#endif
    int n;
    cin>>n;
    int x=7;
    int count=0;
    for(int i=1;i<=n;i++)
    {
        if(x%n==0) {
        	cout<<i<<"\n"; 
        	count=1; 
        	break;
        }
        else x = ( (x*10) +7) %n;
    }
    if(count==0) 
    	cout<<-1<<"\n";
    return 0;
}
