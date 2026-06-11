//#include<bits/stdc++.h>
#include<iostream>
using namespace std;

typedef long long ll;
const int N = 2000006;



int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int a,b,c;
	cin>>a>>b>>c;
	if(a + b + c >= 22){
		cout<<"bust";
	}else{
		cout<<"win";
	}
	
	return 0;
}
