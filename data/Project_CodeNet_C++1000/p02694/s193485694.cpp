#include<bits/stdc++.h>
using namespace std;

int main(){
	long long goal;
	cin>>goal;
	long long curr = 100;
	long long ret = 0;
	while(curr<goal){
		curr+=curr/100;
		ret++;
	}
	cout<<ret;
}