#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	long long int k;
	int n;
	cin>>n>>k;
	int v[n];
    int town, count=0,i=0;
    int a[n];
    memset(v,-1,sizeof v);
    v[0]=0;

    for(int j=0;j<n;j++)
    cin>>a[j];
    if(k<n)
    {
    while(count<k)
    {
    i=a[i]-1;
    count++;    
    }
    }  
    else
    { 
    while(count<k)
    {
    i=a[i]-1;
    count++;
    if(v[i]==-1)
    {
    v[i]=count;
    }
    else
    {
    town=i;
    break;	
    }
    }

    int r=(k-v[town])%(count-v[town]);
    i=town;
    while(r>0)
    {
    	i=a[i]-1;
    	r--;
    }
    }
    cout<<i+1;
    return 0;
}