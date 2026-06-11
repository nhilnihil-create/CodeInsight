//Author: Fuadul Hasan(fuadul202@gmail.com)
//BSMRSTU,Gopalganj

#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int N   = 2e5 + 5;

int main(){

	int n,m;
	cin>>n>>m;
	int x = (m*2)+1;
	if(n%x==0)
		cout<<(n/x)<<endl;
	else cout<<(n/x)+1<<endl;
}

