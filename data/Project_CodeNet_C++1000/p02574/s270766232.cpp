#include<bits/stdc++.h>
using namespace std;


int main()
{
  	int n;
  	cin>>n;
  	
  	int a;
  	
  	int maxV=1e6+1;
  	int flag[maxV]={0};
  	
  	int gcd=0;
  	
  	for(int i=0;i<n;i++)
  	{
  	    cin>>a;
  	    flag[a]++;
  	    
  	    gcd=__gcd(gcd,a);
  	}
  	
  	bool f1=true;
  	
  	for(int i=2;i<maxV;i++)
  	{
  	    int cnt=0;
  	    for(int j=i;j<maxV;j+=i)
  	    {
  	        cnt+=flag[j];
  	    }
  	    
  	    if(cnt>1)
  	        f1=false;
  	}
  	
  	if(f1)
  	{
  	    cout<<"pairwise coprime"<<endl;
  	}
  	else if(gcd==1)
  	{
  	    cout<<"setwise coprime"<<endl;
  	}
  	else
  	{
  	    cout<<"not coprime"<<endl;
  	}
  	
  	return 0;
}