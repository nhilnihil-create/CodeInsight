#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	if(n%2==0) cout<<"0.500000000";
	else cout<<(double)(n/2+1)/n;
}
