#include <bits/stdc++.h>
using namespace std;
int main()
{
	char a[10];
	for(int i=0;i<6;i++){
		cin>>a[i];
	}
	if(a[2]==a[3]&&a[4]==a[5])cout<<"Yes";
	else cout<<"No";
}