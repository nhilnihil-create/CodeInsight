#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,m=1,min,k;
	cin>>n;
	int r[n];
	cin>>r[0];
	min=r[0];
	for(int i=1;i<n;i++){
		cin>>r[i];
		k=r[i];
		if(k<min){
			min=k;
			m++;
		}
	}
	cout<<m;
}
