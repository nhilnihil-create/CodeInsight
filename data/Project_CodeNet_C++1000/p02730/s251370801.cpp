#include<iostream>
#include<stdio.h>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cmath>
#define ll long long 
#define d double
using namespace std;

int main()
{
	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s;
    cin>>s;
    size_t n=s.size();
    n=n-1;
    int l=0;
    while(n>l)
    {
    	if(s[l++]!=s[n--])
    	{
    		cout<<"No"<<endl;
    		return 0;
    		
		}
    	
	}
	
	n=s.size();
	int n1=((n-1)/2);
	n1=n1-1;
	int l1=0;
	while(n1>l1)
	{
    	if(s[l1++]!=s[n1--])
    	{
    		cout<<"No"<<endl;
    		return 0;
    		
		}
		
	}
    
    n=s.size();
    int l2=((n+3)/2);
    l2=l2-1;
    size_t n3=s.size();
    n3=n3-1;
    while(n3>l2)
    {
    	if(s[l2++]!=s[n3--])
    	{
    		cout<<"No"<<endl;
    		return 0;
    		
		}
    	
	}
		
 
    cout<<"Yes"<<endl;
    
    
    return 0;   
}