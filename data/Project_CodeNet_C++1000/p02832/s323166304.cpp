#include<bits/stdc++.h>
using namespace std;
int n;
int a[222222];
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	int ptr=1;
	int cnt=0;
	for(int i=0;i<n;i++)
		if(a[i]==ptr){
			cnt++;
			ptr++;
		}
	if(cnt==0)
		cout<<-1<<endl;
	else
		cout<<n-cnt<<endl;
	return 0;
}