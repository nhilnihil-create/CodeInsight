#include<bits/stdc++.h>
using namespace std;
long long kill(long long health){
	if(health==1) return 1;
	return 1+kill(health/2)*2;
}
int main(){
	long long h;
	cin>>h;
	cout<<kill(h);
}