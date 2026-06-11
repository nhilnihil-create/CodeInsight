#include<bits/stdc++.h>
using namespace std;

int n;  int frq[10][10];

string s;

int main()
{
	
	cin>>n; long long sum=0;
	
	for( int i=1;i<=n;i++)
	{
		s= to_string(i);
		int l= s.size();
		
		if( s[l-1]!='0') //if last is zero first should be zero..but 01 is 1..so discard it
		{  
			int x= s[0]   - '0';
			int y= s[l-1] - '0';
			
			 // cout<<x<<" "<<y <<" 1st"<<endl;
			
			frq[x][y]++ ;  //to store first digit ans last digit occurence
		}
		
	}
	
	/* cout<<"freqarray"<<endl;
		
		for( int i=1;i<=9;i++)
		{   
		    cout<<"row"<<i<<"--> ";
			for( int j=1;j<=9;j++)
			cout<< frq[i][j]<<" ";
			cout<<endl;
		}
		
		*/
	
		//multiply a[i][j]*a[j][i] ...for i ,j how many element occurs
		
		for( int i=1;i<=9;i++)
		{
			for( int j=1;j<=9;j++)
			sum= sum + frq[i][j]*frq[j][i];  //total element
		}
		
		cout<<sum<<endl;
	}
