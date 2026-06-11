#include<stdio.h>
#include<iostream>
using namespace std;

int main()
{	
	int N, X, T;
  	cin >>N >>X >>T;
  	int count = 0;
  	while (N > 0)
  	{
  		N -= X;
    	count ++;
  	}
  	cout <<count*T<<"\n";
	return 0;
}