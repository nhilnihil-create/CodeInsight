//Author: Fuadul Hasan(fuadul202@gmail.com)
#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int N   = 2e5 + 5;

int main(){
	
	int a[3];
	for(int i=0;i<3;i++){
		cin>>a[i];
	}

	sort(a,a+3);
	cout<<a[0]+a[1]<<endl;


	

	return 0;
}