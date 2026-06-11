//#include<bits/stdc++.h>
#include<iostream>
using namespace std;

typedef long long ll;
const int N = 2000006;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int a,b;
	cin>>a>>b;
	if( a < b){
		for(int i=0;i<b;i++)cout<<a;
	}else{
		for(int i=0;i<a;i++)cout<<b;
	}
	
	return 0;
}
