//Author: Fuadul Hasan(fuadul202@gmail.com)
#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int N   = 2e5 + 5;
int m[10];

int main(){
	
	
	int a,b;
	cin>>a>>b;

	m[a] = 1;
	m[b] = 1;
	if(m[1] == 0){
		cout<<1<<endl;
	}else if(m[2] == 0){
		cout<<2<<endl;
	}else{
		cout<<3<<endl;
	}

	

	return 0;
}