#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{	
	int n;
	cin>>n;
	if(n >= 3)
	{
		int ar[n];
		for (int i = 0; i < n; i++ )
			cin>>ar[i];
		int count =0;
		for(int i=0 ; i < n; i++) {	
			for (int j = i+1; j < n; j++)	{
				for (int k = j+1; k < n; k++)	{
					if( ar[i] != ar[j] && ar[j] != ar[k] && ar[k] != ar[i])
					if( ar[i] + ar[j] > ar[k] && ar[j] + ar[k] > ar[i] && ar[i] + ar[k] > ar[j])
						{		
							count++;
						}
					}
			}
		}
	cout<<count<<"\n";
	}
	else cout<<"0"<<"\n";	
	return 0;
}