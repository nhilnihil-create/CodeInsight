#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	
	int happ=0;
	happ+=(n/500)*1000;
	n=n%500;
	happ+=(n/5)*5;
	cout<<happ;
}
