#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
int main() {
	// your code goes here
	int h,w,n;
	cin>>h>>w>>n;
	int m=h>w? h:w;
	if(n%m==0)
	cout<<n/m<<endl;
	else
	cout<<n/m+1<<endl;
	return 0;
}