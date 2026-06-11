//Author: Fuadul Hasan(fuadul202@gmail.com)
//BSMRSTU,Gopalganj

#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int N   = 2e5 + 5;

int main(){

	int n,m;
	cin>>n>>m;
	int x = m - n+1;
	int y = m+n;
	for(int i=x;i<y;i++)
		cout<<i<<" ";
	cout<<endl;


	return 0;
}

